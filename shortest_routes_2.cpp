#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;

void solve(vector<vector<ll>>&v, int q)
{
    int n = v.size()-1;
    for(int i=1; i<=n; i++)v[i][i] = 0;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(v[i][k] != LLONG_MAX && v[k][j] != LLONG_MAX)
                {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
    }
    for(int i=0; i<q; i++)
    {
        int a, b;
        cin>>a>>b;
        if(v[a][b] == LLONG_MAX)cout<<-1<<'\n';
        else cout<<v[a][b]<<'\n';
    }
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>>v(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i=0; i<m; i++)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        v[a][b] = c;
        v[b][a] = c;
    }
    solve(v, q);
}

