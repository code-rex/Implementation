//Bredth first search
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int vertex;
    list<int> *adj;
   public:
       Graph(int w);
       void addedge(int u,int v);
       void bfs(int s);
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
    adj[v].push_back(u);//   Wrong approach for directed graph to visit all node(In disconnected graph)(only apply when the the graph is directed)
}
void Graph::bfs(int s)
{
    bool* visited=new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    visited[s]=true;
    list<int>q;
    q.push_back(s);
    while(!q.empty())
    {
       int s=q.front();
       cout<<s<<" ";
       q.pop_front();
       for(list<int>::iterator i=adj[s].begin();i!=adj[s].end();i++)
       {
           if(!visited[*i])
           {
               visited[*i]=true;
               q.push_back(*i);
           }
       }
    }
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
    cout<<"BFS ";
    g.bfs(vertex);
    cout<<endl;
    }
    return 0;
}
