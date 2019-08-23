vector<vector<int>>adj;
vector<int>color;
bool iscycle;

void dfs(int i)
{
    color[i]=1;
    for(auto w:adj[i])
    {
        if(color[i]==2)
            continue;
        if(color[i]==1)
            iscycle=1;
        if(color[i]==0)
            dfs(w);
    }
    color[i]=2;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    adj.resize(A);
    iscycle=0;
    adj.clear();
    color.assign(A,0);
    
    for(int i=0;i<B.size();i++)
        adj[B[i]-1].push_back(C[i]-1);
    
    for(int i=0;i<A;i++)
        if(color[i]==0)
            dfs(i);
    return !iscycle;
}
