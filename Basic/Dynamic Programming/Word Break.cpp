/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or 
more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
*/


bool wordBreak(string s, vector<string>& wordDict) {
      int n=s.size();
      unordered_set<string>set(wordDict.begin(),wordDict.end());
      vector<int>dp(n+1,0);dp[n]=1;
        
      for(int i=n-1;i>=0;i--)
          for(int j=i;j<n;j++)
          {
              string p=s.substr(i,j-i+1);
              //This is valid string and beyond this is also valid
              if(set.find(p)!=set.end() && dp[j+1]==1) 
              {
                  dp[i]=1;
                  break;
              }
          }
        return dp[0];
    }
