//counting maximum subarray of 0 (making all 1 equals to -1)
vector<int> Solution::flip(string p) {
    int start=0,end=0,s=0;
        int sum=0;
        int maxsum=INT_MIN;
        vector<int>ans;
        for(int i=0;i<p.length();i++)
        {
            int c=p[i]-'0';
            int value = (c==0)?1:-1;
            sum+=value;
            if(sum<0)
            {
                sum=0;
                s=i+1;
            }
            else if(maxsum<sum)
            {
                maxsum=sum;
                start = s;
                end = i;
            }
        }
        if(maxsum>0)
        {
            ans.push_back(start+1);
            ans.push_back(end+1);
        }
        return ans;
}
