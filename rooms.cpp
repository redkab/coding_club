#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>&grid, int sr, int sc)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int>dr = {0, 0, 1, -1};
    vector<int>dc = {1, -1, 0, 0};
    grid[sr][sc] = '#';
    queue<int>qr;
    queue<int>qc;
    qr.push(sr);
    qc.push(sc);
    int r,c, nr, nc;

    while(!qr.empty() && !qc.empty())
    {
        r = qr.front();
        c = qc.front();
        qr.pop();
        qc.pop();

        for(int i=0; i<4; i++)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr >=0 && nr<m && nc>=0 && nc<n)
            {

                if(grid[nr][nc] == '.')
                {
                    grid[nr][nc] = '#';
                    qr.push(nr);
                    qc.push(nc);
                }
            }
        }
    }
}


int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>>v(m, vector<char>(n));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>v[i][j];
        }
    }

    int count=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j] == '.')
            {
                bfs(v, i, j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}









