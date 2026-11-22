#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int>dp;

int f(vector<int>&v, int x)
{
    if(dp[x] != -1)return dp[x];
    int ans = INT_MAX;
    for(int c : v)
    {
        if(c>x)break;
        ans = min(ans, f(v, x-c));
    }
    ans++;
    return dp[x] = ans;
}


int main()
{
    int n, x;
    cin>>n>>x;
    vector<int>c(n);
    dp.assign(x+1, -1);
    dp[0] = 0;
    for(int i=0; i<n; i++)cin>>c[i];
    sort(c.begin(), c.end());
    for(int k:c)dp[k] = 1;
    cout<<f(c, x)<<'\n';
}
