#include<iostream>
using namespace std;
typedef long long int ll;

bool touch(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    if((y2-y1)*(x4-x3) != (y4-y3)*(x2-x1))return 1;
    if((y3-y1)*(x3-x2) == (y3-y2)*(x3-x1))return 1;
    return 0;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x1, x2, x3, x4, y1, y2, y3, y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if(!touch(x1, y1, x2, y2, x3, y3, x4, y4))cout<<"NO\n";
        else if(meet(x1, y1, x2, y2, x3, y3, x4, y4))cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
