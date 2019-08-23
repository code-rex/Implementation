//0 indexing DFS Coloring Approach 0->white 1->grey 2->black 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>color;
bool iscycle;

void dfs(int v)
{
	color[v]=1; //Grey
	for(auto i:adj[v])
	{
		if(color[i]==2)	//It optimises speed so fast
			continue;
		if(color[i]==1) //Cycle is Found
			iscycle=1;
		if(color[i]==0)
			dfs(i);
	}
	color[v]=2;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int nodes,edges;
		cin>>nodes>>edges;
		adj.resize(nodes);
		adj.clear(); //Important line for multiple test cases
		
		for(int i=0;i<edges;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		iscycle=0;
		color.assign(nodes,0);
		
		for(int i=0;i<nodes;i++)
			if(color[i]==0){
				dfs(i);
				if(iscycle)
					break;
			}
		cout<<iscycle<<" ";
	}
	return 0;
}
