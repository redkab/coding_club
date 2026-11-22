#include<iostream>
using namespace std;

bool touch(long long int a1, long long int b1, long long int c1, long long int a2, long long int b2, long long int c2)
{
    if(a1*b2 != b1*a2)return 1;
    if((a1*c2 == a2*c1) && (b1*c2 == b2*c1))return 1;
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        long long int dx1, dx2, dy1, dy2, sx1, sy1, sx2, sy2;

        dx1 = x2-x1;
        dx2 = x4-x3;
        sx1 = x1+x2;
        sx2 = x3+x4;

        dy1 = y2-y1;
        dy2 = y4-y3;
        sy1 = y1+y2;
        sy2 = y3+y4;

        long long int a1, a2, b1, b2, c1, c2;

        a1 = 2*dx1;
        b1 = 2*dy1;
        c1 = dx1*sx1 + dy1*sy1;

        a2 = 2*dx2;
        b2 = 2*dy2;
        c2 = dx2*sx2 + dy2*sy2;

        if(touch(a1, b1, c1, a2, b2, c2))cout<<"Yes\n";
        else cout<<"No\n";
    }

}
