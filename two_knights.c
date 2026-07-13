#include<stdio.h>

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

long long numWays(long long k)
{
    return k*k*(k*k-1)/2 - 4*(k-1)*(k-2);
}
    
int main()
{
    long long int n;
    scanf("%lld", &n);
    for(long long int i=1; i<=n; i++)
    {
        printf("%lld\n", numWays(i));
    }

}

