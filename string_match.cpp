#include<iostream>
#include<vector>
using namespace std;

bool valid(string s, string p, int ind)
{
    for(int i=0; i<p.size(); i++)
    {
        if(s[ind+i]!=p[i])return 0;
    }
    return 1;
}

int count(string s, string p)
{
    char start = p[0];
    vector<int>v;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == start)v.push_back(i);
    }
    int c=0;

    for(int n:v)
    {
        if(valid(s, p, n))c++;
    }
    return c;
}

int main()
{
    string s, p;
    cin>>s;
    cin>>p;
    cout<<count(s, p)<<endl;
}
    
    
