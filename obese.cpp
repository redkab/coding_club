#include<iostream>
using namespace std;
int main()
{
    int ch, w;
    cin >> ch >> w;
    float mh, bmi;
    mh = (float)ch/100;
    bmi = (float)w;
    bmi/=mh;
    bmi/=mh;
    if(bmi>=25)cout<<"Yes\n";
    else cout<<"No\n";
}
