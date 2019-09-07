//Two Pointer Algorithm
int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end]]==0) //Increase the counter if not found move right
              counter++;
            map[s[end++]]++;
            while(counter>k){ //if more than k increase the start
              if(map[s[begin]]==1) //if is 1 means distinct of current windows hence decrease counter
                counter--;
              map[s[begin++]]--
             }
            d=max(d, end-begin);
        }
        return d;
    }
