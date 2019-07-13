/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int>ans;
    int n=A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    //Set for no two same indices
    set<pair<int,int>>s;
    //Making max heap with tuple
    priority_queue< pair<int, pair<int,int> > >pq;
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    
    int count=0;
    while(count<n)
    {
        pair<int,pair<int,int>>tuple=pq.top();
        pq.pop();
        ans.push_back(tuple.first);
        int i=tuple.second.first;
        int j=tuple.second.second;
        
        if(s.find({i-1,j}) == s.end())
        {
            s.insert({i-1,j});
            pq.push({A[i-1]+B[j],{i-1,j}});
        }
        if(s.find({i,j-1}) == s.end())
        {
            s.insert({i,j-1});
            pq.push({A[i]+B[j-1],{i,j-1}});
        }
        count++;
    }
    return ans;
}
