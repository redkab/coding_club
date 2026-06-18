#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
typedef long long ll;

vector<ll> cost(vector<vector<pair<ll, ll>>>&adj, ll s)
{
    ll n = adj.size(), cd, curr;
    vector<ll>dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll , ll>>, greater<pair<ll, ll>>>pq;
    pq.push({0, s});
    dist[s] = 0;
    pair<ll, ll>x;
    while(!pq.empty())
    {
        x = pq.top();
        pq.pop();
        curr = x.second;
        cd = x.first;
        if(cd > dist[curr])continue;
        for(pair<ll, ll> it : adj[curr])
        {
            ll adjNode = it.first;
            ll weight = it.second;
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
    vector<vector<pair<ll, ll>>>al(n);
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        al[a-1].push_back({b-1, c});
    }
    vector<ll>dist = cost(al, 0);
    for(int i=0; i<dist.size(); i++)
    {
        cout<<dist[i]<<' ';
    }
    return 0;
}






