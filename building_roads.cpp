#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&al, vector<bool>&vis, int start, vector<vector<int>>&isls)
{
    queue<int>q;
    q.push(start);
    vis[start] = 1;
    int n;
    vector<int>v;
    
    while(!q.empty())
    {
        n = q.front();
        q.pop();
        v.push_back(n);
        for(int neigh : al[n])
        {
            if(!vis[neigh])
            {
                q.push(neigh);
                vis[neigh] = 1;
            }
        }
    }
    isls.push_back(v);
}

int main()
{
    int n, m, a, b, count=0;
    cin >> n >> m;
    vector<vector<int>>al(n+1);
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    vector<vector<int>>isls;
    vector<bool>vis(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            bfs(al, vis, i, isls);
            count++;
        }
    }
    cout<<count-1<<endl;
    for(int i=0; i<count-1; i++)
    {
        cout<<isls[i][0] << ' ' << isls[i+1][0]<<endl;
    }
    return 0;
}


