#include<bits/stdc++.h>
using namespace std;

bool moveMonsters(vector<vector<char>>&grid, queue<pair<int, int>>&q)
{
    if(!q.size())return 0;
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
            if(nr >=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] != '#' && grid[nr][nc] != 'M')
            {
                grid[nr][nc] = 'M';
                pair<int, int>p;
                p.first = nr;
                p.second = nc;
                q.push(p);
            }
        }
    }
    return 1;
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

string findPath(vector<vector<char>>&grid, int sr, int sc, queue<pair<int, int>>&qp)
{
    int m = grid.size();
    int n = grid[0].size();
    int r, c, nr, nc;
    vector<vector<char>>par(m, vector<char>(n));

    queue<int>qr;
    queue<int>qc;
    qr.push(sr);
    qc.push(sc);
    grid[sr][sc] = '#';

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    while(!qr.empty() && !qc.empty())
    {
        moveMonsters(grid, qp);
        r = qr.front();
        c = qc.front();
        qr.pop();
        qc.pop();
        if(r == 0 || r == m-1 || c == 0 || c == n-1)break;

        for(int i=0; i<4; i++)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] != '#' && grid[nr][nc] != 'M' && grid[nr][nc]!='V')
            {
                qr.push(nr);
                qc.push(nc);
                grid[nr][nc] = 'V';
                switch(i)
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
        }
        printGrid(grid);
    }
    string emp;
    if(!(r == 0 || r == m-1 || c == 0 || c == n-1))return emp;

    map<char, char>mp;
    mp['L'] = 'R';
    mp['R'] = 'L';
    mp['U'] = 'D';
    mp['D'] = 'U';
    string path;
    while(!(r == sr && c == sc))
    {
        if(c == '\0')return path;
        path.push_back(mp[par[r][c]]);
        switch(par[r][c])
        {
            case 'R':
                c++;
                break;
            case 'L':
                c--;
                break;
            case 'U':
                r--;
                break;
            case 'D':
                r++;
                break;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}






int main()
{
    int m,n, sr, sc;
    cin >> n >> m;
    queue<pair<int, int>>q;
    int k=0;
    //string maze = "#########.....A##.#######......##.####.##....#.##.##.#.##..M.#.#";
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
      //      grid[i][j] = maze[k++];
            if(grid[i][j] == 'M')
            {
                q.push(make_pair(i, j));
            }
            if(grid[i][j] == 'A')
            {
                sr=i;
                sc=j;
            }
        }
    }
    string ans = findPath(grid, sr, sc, q);
    if(!ans.length())
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<ans.length()<<'\n';
    cout<<ans<<'\n';
    return 0;

}
    


