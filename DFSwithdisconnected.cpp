#include<bits/stdc++.h>
using namespace std;
void dfsutil(int s,vector<bool>&visited,vector<int>adj[])
{
    stack <int> st;
    st.push(s);
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        if(!visited[s])
        {
            cout<<s<<" ";
            visited[s]=true;
        }
        for(int i=adj[s].size()-1;i>=0;i--)
        {
            if(!visited[adj[s][i]])
            {
                st.push(adj[s][i]);
            }
        }
    }
}
void DFS(vector<int>adj[],int vertex)
{
    vector<bool>visited(vertex+1,false);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            dfsutil(i,visited,adj);
    }
}
int main()
{
    int vertex;
    cin>>vertex;
    int edge;
    cin>>edge;
    vector<int>adj[vertex];
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
       adj[b].push_back(a);
    }
    DFS(adj,vertex);
    return 0;
}
