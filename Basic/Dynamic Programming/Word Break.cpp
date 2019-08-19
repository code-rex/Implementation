/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or 
more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
*/


bool search(string a,vector<string>&B)
{
    for(int i=0;i<B.size();i++)
        if(a==B[i])
            return true;
    return false;
}
int Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    vector<int>dp(n+1,0);
    dp[n]=1;
    //traversing from back
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            string p=A.substr(i,j-i+1);
            
            if(search(p,B) && dp[j+1]==1)
            {
                dp[i]=1;
                break;
            }
        }
    }
    return dp[0];
}
