#include<bits/stdc++.h>
using namespace std;

float dp(vector<float>&a, vector<float>&b)
{
    float sum=0;
    int n = a.size();
    for(int i=0; i<n; i++)
    {
        sum += a[i]*b[i];
    }
    return sum;
}

float fwb(vector<float>&w, float b, vector<float>&x)
{
    return dp(w, x) + b;
}

float j(vector<vector<float>>&x, vector<float>&w, vector<float>&y, float b)
{
    int m = x.size();
    float s=0;
    float diff;
    for(int i=0; i<m; i++)
    {
        diff = f(w, b, x[i]) - y[i];
        s += diff*diff;
    }
    return s/(2.0f * m);
}

float djk(vector<vector<float>>&x, vector<float>&w, float b, vector<float>&y, int k)
{
    float s=0;
    int m = x.size();
    float term;
    for(int i=0; i<m; i++)
    {
        term = (f(w, b, x[i]) - y[i])*x[i][k];
        s += term;
    }
    return s/(1.0f * m);
}

float djb(vector<vector<float>>&x, vector<float>&w, float b, vector<float>&y)
{
    float s=0;
    int m = x.size();
    for(int i=0; i<m; i++)
    {
        s += f(w, b, x[i]) - y[i];
    }
    return s/(1.0f * m);
}

vector<float> gradDesc(vector<vector<float>>&x, vector<float>&y)
{
    int m = x.size();
    int n = x[0].size();
    vector<float>w(n, 0.0);
    float b=0;
    float a = 0.001;
    vector<float>temp(n, 0.00);
    for(int i=0; i<10000; i++)
    {
        cout<<"Running iteration"<<i<<'\n';
        for(int k=0; k<n; k++)
        {
            temp[k] = w[k] - a*djk(x, w, b, y, k);
        }
        b = b - a*djb(x, w, b, y);
        w=temp;
    }
    w.push_back(b);
    return w;
}



    
