/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

 string longestPalindrome(string a) {
        if(a.size()<=0)
            return "";
        int maxlen=1,len=0;
        int low,high,n=a.size(),start=0;
        
        for(int i=1;i<n;i++)
        {
            //even palindromes
            int count=0;
            while(count<2){
            if(count++==0)
               low=i-1,high=i; //even Palindrome
            else
               low=i-1,high=i+1; //odd palindrome
            while(low>=0 && high<n && a[low]==a[high]){
                if(high-low+1 > maxlen)
                {
                    start=low;
                    maxlen=high-low+1;
                }
                low--,high++;
            }
          }
        }
       // cout<<maxlen<<" "<<start;
        return a.substr(start,maxlen);
    }
