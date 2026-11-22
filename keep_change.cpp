#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n), b(n);
    vector<string>s(n);

    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i]>>s[i];
    }

    int mon = 10000;
    int optmon = 10000;

    for(int i=0; i<n; i++)
    {
        optmon -= a[i];
        if(s[i] == "keep")mon -= b[i];
        else mon -= a[i];
    }

    cout<<optmon - mon<<endl;
}
