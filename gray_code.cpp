#include<bits/stdc++.h>
using namespace std;

string toBin(int n, int cap)
{
    string ans;
    while(n)
    {
        ans.push_back((n&1) + '0');
        n>>=1;
    }
    while(ans.length()<cap)ans.push_back('0');
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{
    int n;
    cin>>n;
    int power = pow(2, n);
    for(int i=0; i<power; i++)
    {
        cout<<toBin(i, n)<<endl;
    }
    return 0;
}
