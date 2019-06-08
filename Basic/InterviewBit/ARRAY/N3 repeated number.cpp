//Moores Voting algorithm
//Space O(1)

int Solution::repeatedNumber(const vector<int> &a) {
    int n=a.size();
    int count1=0,count2=0,first=INT_MAX,second=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]==first)
        count1++;
        else if(a[i]==second)
        count2++;
        else if(count1==0)
        {
            count1++;
            first=a[i];
        }
        else if(count2==0)
        count2++,second=a[i];
        else
        count1--,count2--;
    }
    count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==first)
        count1++;
        if(a[i]==second)
        count2++;
    }
    if(count1>n/3)
    return first;
    if(count2>n/3)
    return second;
    else 
    return -1;
    
}
