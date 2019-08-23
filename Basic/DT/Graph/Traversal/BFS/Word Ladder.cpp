//https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    unordered_set<string>dict(dictV.begin(),dictV.end());
    queue<string>todo;
    todo.push(start);
    int ladder=1;
    while(!todo.empty())
    {
        int n=todo.size();
        for(int i=0;i<n;i++)
        {
            string word=todo.front();
            todo.pop();
            if(word==end)
                return ladder;
            dict.erase(word);
            for(int j=0;j<word.size();j++)
            {
                char c=word[j];
                for(int k=0;k<26;k++)
                {
                    word[j]='a'+k;
                    if(dict.find(word)!=dict.end())
                        todo.push(word);
                }
                word[j]=c;
            }
        }
        ladder++;
    }
    return 0;
}
