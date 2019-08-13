/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
*/

int lengthOfLongestSubstring(string s) {
        int len=0,start=0,end=0,size=s.size(),counter=0;
        vector<int>map(128,0);
        while(end<size)
        {
            if(map[s[end++]]++ > 0) 
                counter++;
            if(counter>0)
            {
                if(map[s[start++]]-- > 1) counter--;
            }
            len=max(len,end-start);
        }
        return len;
    }
