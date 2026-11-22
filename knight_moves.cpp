#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void printGrid(vector<vector<int>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void bfs(vector<vector<int>>&v, int sr, int sc)
{
    int n = v.size();
    vector<vector<bool>>vis(n, vector<bool>(n, 0));
    queue<int>qr, qc;
    qr.push(sr);
    qc.push(sc);
    vis[sr][sc] = 1;
    int nr, nc, r, c,  lev=0;

    while(!qr.empty())
    {
        int s = qr.size();
        for(int a=0; a<s; a++)
        {
            r = qr.front();
            c = qc.front();
            qr.pop();
            qc.pop();
            v[r][c] = lev;

            for(int i=0; i<8; i++)
            {
                nr = r + dr[i];
                nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc])
                {
                    qr.push(nr);
                    qc.push(nc);
                    vis[nr][nc] = 1;
                }
            }
        }
        lev++;
    }
}



int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n, vector<int>(n, -1));
    bfs(v, 0, 0);
    printGrid(v);
}


