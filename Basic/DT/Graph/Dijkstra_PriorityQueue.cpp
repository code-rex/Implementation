#include<bits/stdc++.h>
using namespace std;
#define inf 0xc007
vector<int> ShortestPath(vector<pair<int,int>>adj[],int v,int src)
{
	priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq;
	vector<int>dist(v,inf);

	pq.push({0,src});
	dist[src]=0;

	while(!pq.empty())
	{
		//1.The First vertex in pq is minimum distance vertex,extract it from priority queue.(pq sort item by first )
		//2.Vertex label is stored in second of pair
		int u=pq.top().second;
		pq.pop();

		for(auto x : adj[u])
		{
			int v = x.first;
			int weight = x.second;

			if(dist[v] > dist[u]+weight)
			{
				dist[v] = dist[u]+weight;
				pq.push({dist[v],v});
			}
		}
	}
	return dist;
}
int main()
{
	int v,edges;
	cin>>v>>edges;
	vector<pair<int,int>>adj[v+1];
	while(edges--)
	{
		int src,dest,weight;
		//Making undirected graph
		cin>>src>>dest>>weight;
		adj[src].push_back({dest,weight});
		adj[dest].push_back({src,weight});
	}
	int k=0;
	for(auto i:ShortestPath(adj,v,0))
		cout<<k+1<<" "<<i<<endl;
	return 0;
}
