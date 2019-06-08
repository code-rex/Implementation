int Solution::maximumGap(const vector<int> &a){
    int n=a.size();
    if(n<2)
        return 0;
        
    int min1=a[0],max1=a[0];
    for(int i=1;i<n;i++)
    {
        min1=min(min1,a[i]);
        max1=max(max1,a[i]);
    }
    
    int gap=0;
    gap=(max1-min1)/(n-1);
    
    if(gap==0)
        return max1-min1;
    
    vector<int>minbucket(n,-1);
    vector<int>maxbucket(n,-1);
    
    //code
    for(int i=0;i<n;i++)
    {
        int bucket=(a[i]-min1)/gap;
        if(minbucket[bucket]<0)
        {
            minbucket[bucket]=a[i];
            maxbucket[bucket]=a[i];
        }
        else
        {
            minbucket[bucket]=min(minbucket[bucket],a[i]);
            maxbucket[bucket]=max(maxbucket[bucket],a[i]);
        }
    }
    
    int index=0;
    int result=0;
    for(int i=0;i<n;i++){
    //cout<<maxbucket[i]<<" ";
        if(minbucket[i]>=0)
            {
                result=max(result,minbucket[i]-maxbucket[index]);
                index=i;
            }
    }
    return result;
}
