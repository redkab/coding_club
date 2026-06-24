#include<bits/stdc++.h>
using namespace std;

void count(vector<vector<int>>&al)
{
    int leaf=0, x=0;
    int n = al.size();
    for(int i=0; i<al.size(); i++)
    {
        if(al[i].size() ==  1)leaf++;
    }
    x = n - leaf - 1;
    int y = leaf/x;
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
