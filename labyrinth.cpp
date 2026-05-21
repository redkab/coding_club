#include<bits/stdc++.h>
using namespace std;
string bfs(vector<vector<char>>&grid, vector<vector<char>>&par, int sr, int sc, int er, int ec)
{
    string path;
    queue<int>qr;
    queue<int>qc;
    qr.push(sr);
    qc.push(sc);
    bool flag=0;
    int m = grid.size();
    int n = grid[0].size();
    int r, c, nr, nc;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    grid[sr][sc] = '#';

    while(!qr.empty()&& !qc.empty())
    {
        r = qr.front();
        c = qc.front();
        qr.pop();
        qc.pop();

        for(int i=0; i<4; i++)
        {
            nr = r+dr[i];
            nc = c+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] != '#')
            {
                grid[nr][nc] = '#';
                qr.push(nr);
                qc.push(nc);
                switch (i)
                {
                    case 0:
                        par[nr][nc] = 'L';
                        break;

                    case 1:
                        par[nr][nc] = 'R';
                        break;

                    case 2:
                        par[nr][nc] = 'U';
                        break;

                    case 3:
                        par[nr][nc] = 'D';
                        break;
                }
            }
            if(nr == er && nc == ec)flag=1;
        }
        if(flag)break;
    }
    if(grid[er][ec] != '#')return path;
    r=er, c=ec;
    map<char, char>mp;
    mp['L'] = 'R';
    mp['R'] = 'L';
    mp['U'] = 'D';
    mp['D'] = 'U';

    while(!(r==sr && c==sc))
    {
        path.push_back(mp[par[r][c]]);
        switch(par[r][c])
        {
            case 'U':
                r--;
                break;
            case 'D':
                r++;
                break;
            case 'L':
                c--;
                break;
            case 'R':
                c++;
                break;
        }
    }
    reverse(path.begin(), path.end());
    return path;

}


int main()
{
    int m,n, sr, sc, er, ec;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m));
    vector<vector<char>>par(n, vector<char>(m, '.'));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
            {
                sr = i;
                sc=j;
            }
            if(grid[i][j] == 'B')
            {
                er=i;
                ec=j;
            }
        }
    }
    string x = bfs(grid, par, sr, sc, er, ec);
    int len = x.length();
    if(!len)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<len<<'\n';
    cout<<x<<'\n';
    return 0;
}



