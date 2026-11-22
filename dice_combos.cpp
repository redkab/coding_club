#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<int>dp;
int m = 1e9+7;

int f(int n)
{
    if(n==0)return dp[n] = 1;
    if(dp[n] != -1)return dp[n];
    ll c=0;
    for(int i=1; i<=6 && n-i>=0; i++)
    {
        c = (c + f(n-i))%m;
        c%=m;
    }
    return dp[n] = c;

}
int main()
{
    int n;
    cin>>n;
    dp.assign(n+1, -1);
    dp[1] = 1;
    cout<<f(n)<<'\n';
}
