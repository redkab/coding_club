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

vector<char>parLoop(int n, int i)
{
    if(i==n-1)return {'D'};
    return loopLine(n-i);
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
    vector<vector<char>>grid(n, vector<char>(n));
    if(k==n*n - 1)return grid;
    int c=0, i=0, j=0;
    while(c<k)
    {
        grid[i][j] = 'U';
        cout<<"Filled "<<i<<' '<<j<<'\n';
        if(j != n-1)j++;
        else
        {
            i++;
            j=0;
        }
        c++;
    }
    //printGrid(grid);
    vector<char>par = parLoop(n, j);
    //printVec(par);
    for(int x=0; x<par.size(); x++)
    {
        grid[i][j++] = par[x];
    }
    i++;
    for(int curr = i; curr<n; curr++)
    {
        grid[curr] = loopLine(n);
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

