#include<bits/stdc++.h>
using namespace std;

bool exists(int key, unordered_map<int, int>m)
{
    auto it = m.find(key);
    return !(it == m.end());
}
void count(vector<vector<int>>&al)
{
    unordered_map<int, int>m;
    for(int i=0; i<al.size(); i++)
    {
        if(!exists(al[i].size(), m))
        {
            m[al[i].size()] = 1;
        }
        else m[al[i].size()]++;
    }
    int x, leaf=0, y;
    for(const auto& [a, b] : m)
    {
        if(b==1)x=a;
    }
    int n = al.size();
    y = (n-1)/x - 1;

    cout<<x<<' '<<y<<'\n';
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
