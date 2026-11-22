#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    map<int, int>m;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    cout<<m.size()<<'\n';
}
