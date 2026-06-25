#include<bits/stdc++.h>
using namespace std;

vector<char>loopLine(int n)
{
    vector<char>v(n);
    for(int i=0; i<n; i++)
    {
        if(i%2==0)v[i] = 'R';
        else v[i] = 'L';
    }
    if(n%2)v[n-1] = 'L';
    return v;
}

vector<char>fullLine(int n)
{
    vector<char>v(n, 'U');
    return v;
}

vector<char>parLoop(int n, int s)
{
    vector<char>v(n);
    for(int i =0; i<s; i++)
    {
        v[i] = 'U';
    }
    if(s==n-1)
    {
        v[n-1] = 'D';
        return v;
    }
    int j=0;
    vector<char>p = loopLine(n-s);
    for(int i=s; i<n; i++)
    {
        v[i] = p[j++];
    }
    return v;
}

void printVec(vector<char>&g)
{
    for(int i=0; i<g.size(); i++)
    {
        cout<<g[i];
    }
    cout<<'\n';
}

void printGrid(vector<vector<char>>&g)
{
    for(int i=0; i<g.size(); i++)
    {
        printVec(g[i]);
    }
}

vector<vector<char>>makeGrid(int n, int k)
{
    cout<<"Entered\n";
    vector<vector<char>>grid(n);
    if(k == n*n-1)return grid;

    for(int i=0; i<k/n*n; i++)
    {
        grid[i] = fullLine(n);
    }

    grid[k/n*n] = parLoop(n, k%n*n);
    for(int i= k/n*n +1; i<n; i++)
    {
        grid[i] = loopLine(n);
    }
    return grid;

}


int main()
{
    int n, k;
    cin>>n>>k;
    vector<vector<char>>g = makeGrid(n, k);
    if(g.size()==0)cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        printGrid(g);
    }
    return 0;
}

