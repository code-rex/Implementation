/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

string minWindow(string s, string t) {
        vector<int> m(128,0); //can use unordered_map<char,int>m here but that will slow down the program(because ascii of z<128)
        for(int i=0;i<t.size();i++)
            m[t[i]]++;
        //counter represents the no. of chars of t to be found in s
        int start=0,end=0,minlen=INT_MAX,counter=t.size(),minstart=0;
        while(end<s.size())
        {
            //if Character of s found in t decrease the counter
            if(m[s[end]]>0)
                counter--;
            m[s[end]]--; //always decrease the value of m(if not found it goes negative)
            end++;
            while(counter==0) //windows found
            {
                if(end-start<minlen)
                {
                    minlen=end-start;
                    minstart=start;
                }
                m[s[start]]++;
                //if value becomes positive means we again have to find the window
                if(m[s[start]]>0)
                    counter++;
                start++;
                
            }
        }
        if(minlen!=INT_MAX)
            return s.substr(minstart,minlen);
        return "";
    }
