#include<bits/stdc++.h>
using namespace std;

long long int max(long long int a, long long int b)
{
    if(a>b)return a;
    return b;
}


long long int num(long long int r, long long int c)
{
    long long int level = max(r, c);
    long long int del;
    if(level%2)del = -1;
    else del = 1;
    long long int diff = abs(level-c) + abs(r-1);
    long long int start;
    if(level%2)start = level*level;
    else start = (level-1)*(level-1) + 1;
    return start + del*diff;
}


int main()
{
    int t;
    cin>>t;
    long long int y,x;
    while(t--)
    {
        cin>>y>>x;
        cout<<num(y, x)<<'\n';
    }
    return 0;
}
