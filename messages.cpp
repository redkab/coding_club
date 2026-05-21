#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>&al, vector<bool>&vis, vector<int>&par, int st, int end)
{
    queue<int>q;
    vis[st] = 1;
    vector<int>path;
    int x;
    bool flag=0;

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(int y : al[x])
        {
            vis[y] = 1;
            q.push(y);
            par[y] = x;
            if(y==end)flag=1;
        }
        if(flag)break;
    }
    if(!vis[end])return path;
    int t = end;
    while(t!=st)
    {
        path.push_back(t);
        t = par[t];
    }
    reverse(path.begin(), path.end());
    return path;
}


int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>>al(n+1);
    vector<bool>vis(n+1);
    vector<int>par(n+1);
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<int>ans = bfs(al, vis, par, 1, n);
    if(!ans.size())
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}




