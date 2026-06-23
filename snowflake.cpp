#include<bits/stdc++.h>
using namespace std;

void count(vector<vector<int>>&al)
{
    unordered_map<int, int>m;
    for(int i=0; i<al.size(); i++)
    {
        if(!m.contains(al[i].size()))
        {
            m[al[i].size()] = 1;
        }
        else m[al[i].size()]++;
    }
    int x, leaf=0, y;
    for(const auto& [a, b] : m)
    {
        if(b==1)x=a;
        if(a==1)leaf=b;
    }
    cout<<x<<' '<<leaf/x<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, u, v;
        cin>>n>>m;
        vector<vector<int>>al(n);
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            al[u-1].push_back(v-1);
            al[v-1].push_back(u-1);
        }
        count(al);
    }
}
