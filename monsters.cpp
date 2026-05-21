#include<bits/stdc++.h>
using namespace std;

void moveMonsters(vector<vector<char>>&grid, queue<pair<int, int>>&q)
{
    int s = q.size();
    int r, c, nr, nc, m, n;
    m = grid.size();
    n = grid[0].size();
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    for(int j=0; j<s; j++)
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr >=0 && nr<m && nc>=0 && nc<n && grid[nc][nr] != '#' && grid[nr][nc] != 'M')
            {
                grid[nr][nc] = 'M';
                pair<int, int>p;
                p.first = nr;
                p.second = nc;
                q.push(p);
            }
        }
    }
}

void printGrid(vector<vector<char>>&grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
}


int main()
{
    int m,n;
    cin >> n >> m;
    queue<pair<int, int>>q;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == 'M')
            {
                q.push(make_pair(i, j));
            }
        }
    }
    printGrid(grid);
    moveMonsters(grid);
    printGrid(grid);
}
    


