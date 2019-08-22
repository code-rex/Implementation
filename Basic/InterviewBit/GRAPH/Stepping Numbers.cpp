/*
Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.
*/


vector<vector<int>>g;
void dfs(int i,int val,int A,int B,set<int>&s)
{
    val=val*10+i;
    if(val<=B &&val>=A)
        s.insert(val);
    if(val>B)
        return ;
    for(int j=0;j<g[i].size();j++)
    {
        int u=g[i][j];
        dfs(u,val,A,B,s);
    }
}
vector<int> Solution::stepnum(int A, int B) {
    if(A>B)
        swap(A,B);
    for(int i=0;i<=9;i++)
    {
    vector<int> e;
    if(i==0) e.push_back(i+1);
    else if(i==9) e.push_back(i-1);
    else 
    {
        e.push_back(i-1);
        e.push_back(i+1);
    }
        g.push_back(e);
    }
    set<int>s;
    for(int i=0;i<=9;i++)
        dfs(i,0,A,B,s);
    vector<int>ans;
    for(auto i:s)
        ans.push_back(i);
    return ans;
}
