#include<bits/stdc++.h>
using namespace std;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {1, -1, 2, -2, -2, 2, -1, 1};

int inDests(int r, int c, int k)
{
    int nr, nc, in=0;
    for(int i=0; i<8; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if(nr>=0 && nr<k && nc>=0 && nc<k)in++;
    }
    return in;
}


int main()
{
    cout<<inDests(0, 0, 3);
}

