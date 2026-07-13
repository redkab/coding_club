#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void printVec(vector<int>&v)
{
    for(int n:v)
    {
        cout<<n<<' ';
    }
    cout<<'\n';
}
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;

    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        v[i] = i+1;
    }

    for(int i=0; i<(int)s.length(); i++)
    {
        if(s[i] == 'o')reverse(v.begin(), v.begin()+i+1);
        //printVec(v);
    }
    printVec(v);
    return 0;
}
