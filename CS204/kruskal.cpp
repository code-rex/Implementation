#include<bits/stdc++.h>
using namespace std;
//Global Initilization
int nodes,edges;
int id[100];
pair<int,pair<int,int>>p[10000];
//Union-Find Algorithm
void initialize()
{
   for(int i=0;i<nodes;i++)
   	id[i]=i;
}
int root(int x)
{
	while(id[x]!=x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}
void union1(int x,int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}
//Calculating Minimum cost
int kruskal(pair<int,pair<int,int>> p[])
{
	int x,y,cost,minimum_cost=0;
	for(int i=0;i<edges;i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x)!=root(y))
		{
			minimum_cost +=cost;
			union1(x,y);
		}
	}
	return minimum_cost;
}
int main()
{
	cout<<"No. of Nodes and edges"<<endl;
	cin>>nodes>>edges;
	initialize();
	for(int i=0;i<edges;i++)
	{
		cout<<"Enter starting node,ending node and cost"<<endl;
		int x,y,cost;
		cin>>x>>y>>cost;
        p[i] = make_pair(cost,make_pair(x,y));
	}
	sort(p,p+edges);
	int minimum_cost = kruskal(p);
	cout<<minimum_cost<<endl;
	return 0;
}
