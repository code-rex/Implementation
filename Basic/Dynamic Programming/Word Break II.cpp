/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is

[
  "cat sand dog", 
  "cats and dog"
]
*/

vector<string> rec(const string& sentence, const unordered_set<string>& dict,
    unordered_map<string, vector<string>>& found) {
    
    if(found.count(sentence)) 
        return found[sentence];
 
    int n = sentence.size();
    vector<string> result;
    for(int i = 0; i < n; i++) {
        if(dict.find(sentence.substr(0,i+1)) != dict.end()) {
            if(i==sentence.size()-1) {
                result.push_back(sentence);
                break;
            }
            else 
                for(auto& s: rec(sentence.substr(i+1,sentence.size()), dict, found)) 
                    result.push_back(sentence.substr(0,i+1) + " " + s);
        }
    }
 
    found[sentence] = result;
    return result;
}
 
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string, vector<string>> found;
    unordered_set<string>C(B.begin(),B.end());
    return rec(A, C, found);
}
