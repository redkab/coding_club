#include<iostream>
using namespace std;

int crossSign(long long int ax, long long int ay, long long int bx, long long int by)
{
    long long int cp = ax*by - ay*bx;
    if(cp<0)return -1;
    if(cp==0)return 0;
    if(cp>0)return 1;
    return 0;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        int s = crossSign(x2-x1, y2-y1, x3-x1, y3-y1);

        switch(s)
        {
            case -1:
                cout<<"RIGHT"<<endl;
                break;
            case 0:
                cout<<"TOUCH"<<endl;
                break;
            case 1:
                cout<<"LEFT"<<endl;
        }
    }
}
