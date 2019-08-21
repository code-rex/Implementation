#include<bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int v;
vector<pair<int, int>> adj[20000];

bool spfa(int s, vector<int>& d) {
    int n = v;
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<i<<"   "<<d[i]<<endl;
}
int main()
{
    int edges;
    cin>>v>>edges;
    while(edges--)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adj[src].push_back({dest,weight});
    }
    vector<int>d;
    spfa(0,d);
    return 0;
}
