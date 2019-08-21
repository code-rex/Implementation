//All vertex to all vertex Time:O(n^3) DP Problem

#include<bits/stdc++.h>
using namespace std;
#define inf 999999
void floydwarshall(vector<vector<int>>adj)
{
	int n=adj.size();
	vector<vector<int>>d=adj;
	for (int k = 0; k < n; ++k) 
  	  for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            if (d[i][k] < inf && d[k][j] < inf)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

     //printing
     for (int i = 0; i < n; i++)  
    {  
        for (int j = 0; j < n; j++)  
        {  
            if (d[i][j] == inf)  
                cout<<"INF"<<  "    ";  
            else
                cout<<d[i][j]<<"    ";  
        }  
        cout<<endl;  
    } 
        
}
int main()
{
	int v,edges;
	cin>>v>>edges;
	//Implementation is done using adjacency matrix
	vector<vector<int>>adj(v,vector<int>(v,inf));
	for(int i=0;i<v;i++)
		adj[i][i]=0;
	while(edges--)
	{
		int src,dest,weight;
		cin>>src>>dest>>weight;
		adj[src][dest]=weight;
	}	
	floydwarshall(adj);
	return 0;
}
