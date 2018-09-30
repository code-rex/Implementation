//Depth first search
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int vertex;
    list<int> *adj;
    void dfsutil(int s,bool visited1[]);
   public:
       Graph(int w);
       void addedge(int u,int v);
       void bfs(int s);
       void dfs(int s);
       void print();
};
Graph::Graph(int w)
{
    this->vertex=w;
    adj=new list<int>[w];
}
void Graph::addedge(int u,int v)
{
    adj[u].push_back(v);
   // adj[v].push_back(u);  //Only apply for undirected graph not for disconnected graph
}
void Graph::dfsutil(int s,bool visited1[])
{
    visited1[s]=true;
    cout<<s<<" ";
    for(list<int>::iterator it=adj[s].begin();it!=adj[s].end();it++)
    {
        if(!visited1[*it])
            dfsutil(*it,visited1);
    }
}
void Graph::dfs(int s)
{
    bool* visited1=new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited1[i]=false;
    dfsutil(s,visited1);
}
void Graph::print()
{
    cout<<"Adjacency List "<<endl;
    for(int i=0;i<vertex;i++)
    {
        cout<<"Vertex "<<i;
        for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++)
            cout<<"->"<<*it;
        cout<<endl;
    }
}
int main()
{
    int vertex;
    cin>>vertex;
    Graph g(vertex);
    int p;
    cin>>p;
    while(p--)
    {
        int a,b;
        cin>>a>>b;
        g.addedge(a,b);
    }
    g.print();
    while(vertex--){
    cout<<"vertex "<<vertex<<":"<<endl;
    cout<<"DFS ";
    g.dfs(vertex);
    cout<<endl;
    }
    return 0;
}
