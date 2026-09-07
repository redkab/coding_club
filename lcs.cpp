#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcs(string &a, string &b,int i, int j, vector<vector<int>>&dp)
{
    if(i<0 || j<0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(a[i] == b[j])
    {
        return dp[i][j] = 1 + lcs(a, b, i-1, j-1, dp);
    }
    return dp[i][j] = max(lcs(a, b, i, j-1, dp), lcs(a, b, i-1, j, dp));
}

string makeLCS(string &a, string &b, vector<vector<int>>&dp)
{
    int r = dp.size()-1;
    int c = dp[0].size()-1;
    string ans = "";

    while((r>=0 && c>=0) && dp[r][c] != 0)
    {
        if(a[r] == b[c])
        {
            ans.push_back(a[r]);
            r--;
            c--;
        }
        else if (r==0)c--;
        else if(c==0)r--;
        else if(dp[r-1][c] > dp[r][c-1])
        {
            r--;
        }
        else c--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s, t;
    cin>>s;
    cin>>t;
    vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
    lcs(s, t, s.length()-1, t.length()-1, dp);
    string ans = makeLCS(s, t, dp);
    cout<<ans<<'\n';
}

