/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

void generate(int n,string &s,vector<string>&ans,int open,int close)
{
    if(close==n)
    {
        ans.push_back(s);
        return ;
    }
    else
    {
        if(open<n)
        {
            s+="(";
            generate(n,s,ans,open+1,close);
            s.pop_back();
        }
        if(open > close)
        {
            s+=")";
            generate(n,s,ans,open,close+1);
            s.pop_back();
        }
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string>ans;
    string s;
    generate(A,s,ans,0,0);
    return ans;
}
