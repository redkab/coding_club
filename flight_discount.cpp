#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

vector<int> cost(vector<vector<pair<int, int>>>&adj, int s)
{
    int n = adj.size(), cd, curr;
    vector<int>dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int , int>>, greater<pair<int, int>>>pq;
    pq.push({0, s});
    dist[s] = 0;
    pair<int, int>x;
    while(!pq.empty())
    {
        x = pq.top();
        pq.pop();
        curr = x.second;
        cd = x.first;
        if(cd > dist[curr])continue;
        for(pair<int, int> it : adj[curr])
        {
            int adjNode = it.first;
            int weight = it.second;
            if(dist[curr] + weight < dist[adjNode])
            {
                dist[adjNode] = dist[curr] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin>>n>>m;
    int a, b, c;
    vector<vector<pair<int, int>>>al(n);
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        al[a].push_back({b, c});
    }
    vector<int>dist = cost(al, 0);
    for(int i=0; i<dist.size(); i++)
    {
        cout<<dist[i]<<' ';
    }
    return 0;
}







