#include<bits/stdc++.h>

int findMedian(vector<int>&exp, int s, int e)//Find the median of the elements in the range [s,e]
{
    vector<int>frequencies(201, 0);
    for(int i = s; i <= e; i++)
    {
        frequencies[exp[i]]++;
    }
    int d = e-s+1;
    vector<int>v;
    for(int i=1; i<=200; i++)
    {
        for(int k=0; k<frequencies[i]; k++)
        {
            v.push_back(i);
        }
    }
    if(d%2==1)return v[d/2];
    return (v[i/2 -1] + v[i/2])/2;
}
