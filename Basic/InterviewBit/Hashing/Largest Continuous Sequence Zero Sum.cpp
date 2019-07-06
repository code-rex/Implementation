/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the 
 */
 
 vector<int> Solution::lszero(vector<int> &A) {
    vector<int>ans;
    int n=A.size();
    //Mapping sum to Indices(if two same sum has occured means we got zero sum array)
    unordered_map<int,int>m;
    int l=-1,r=-1,length=INT_MIN,sum=0;
    
    m[0]=-1;
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        //found
        if(m.find(sum)!=m.end())
        {
            if(length < i-m[sum])
            {
                length = i-m[sum];
                r = i;
                l = m[sum]+1;
            }
        }
        else
            m[sum]=i;
    }
    if(l>=0 && r>=0)
        for(int i=l;i<=r;i++)
            ans.push_back(A[i]);
    return ans;
}   

