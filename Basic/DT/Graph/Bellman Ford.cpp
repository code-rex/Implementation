//Bellman Ford with Negative cycle (DP)
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int a, b, cost;
};
//v is starting vertex
//t is target vertex 
int n, m, v,t;
vector<edge> e;
const int INF = 1000000000;

void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;

    vector<int> p (n - 1); //for tracing the route
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    for(int i=0;i<n;i++)
    	cout<<i<<"  "<<d[i]<<endl;
    //Case of negative cycle
    if (x == -1)
        cout << "No negative cycle from " << v<<endl;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "Negative cycle: "<<endl;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }

    //Retrieving Path
    if(x==-1)
    {
    	if (d[t] == INF)
        cout << "No path from " << v << " to " << t << "."<<endl;
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": "<<endl;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
    }
}
int main()
{
	v=0;t=3;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int src,dest,weight;
		cin>>src>>dest>>weight;
		e.push_back({src,dest,weight});
		/*e[i].a=src;
		e[i].b=dest;
		e[i].cost=weight;
		*/
	}
	solve();
	return 0;
}
