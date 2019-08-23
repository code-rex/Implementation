/*
Find largest distance
Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes. The goal of the problem is to find largest 
distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a 
unique path between any pair of nodes since it is a tree). The nodes will be numbered 0 through N - 1.

The tree is given as an array P, there is an edge between nodes P[i] and i (0 <= i < N). Exactly one of the i’s will have P[i] equal 
to -1, it will be root node.

 Example:
If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4  
 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3. 
 */
 
 void construct_graph(vector<vector<int>> &G,vector<int> &A)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=-1)
        {
            G[i].push_back(A[i]);
            G[A[i]].push_back(i);
        }
    }
}
int bfs(int u,vector<vector<int>> &G,bool flag)
{
    vector<bool> vis(G.size(),false);
    queue<pair<int,int>> q;  
    q.push({u,0});
    vis[u]=true;
    int d;
    while(!q.empty())
    {
        u=q.front().first;
        d=q.front().second;
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            if(vis[G[u][i]]==false)
            {
                q.push({G[u][i],d+1});
                vis[G[u][i]]=true;
            }
        }
    }
    if(flag == false)
       return u;
    return d;
}
int Solution::solve(vector<int> &A) {
    vector<vector<int>> G(A.size());
    construct_graph(G,A);
    return bfs(bfs(0,G,false),G,true);
}
