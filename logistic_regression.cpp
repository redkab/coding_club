#include<bits/stdc++.h>
using namespace std;

float dp(vector<float>&a, vector<float>&b)
{
    assert(a.size() == b.size());
    float sum=0;
    int n = a.size();
    for(int i=0; i<n; i++)
    {
        sum += a[i]*b[i];
    }
    return sum;
}

float z(vector<float>&w, float b, vector<float>&x)
{
    return dp(w, x)+b;
}

float f(vector<float>&w, float b, vector<float>&x)
{
    float p = pow(2.71828, -z(w, b, x));
    return 1/(1+p);
}

float j(vector<vector<float>>&x, vector<float>&w, vector<float>&y, float b)
{
    int m = x.size();
    float s = 0.0f;

    for(int i = 0; i < m; i++)
    {
        float pred = f(w, b, x[i]);
        pred = max(1e-7f, min(pred, 1.0f - 1e-7f));
        s += -y[i] * log(pred) - (1 - y[i]) * log(1 - pred);
    }

    return s / m;
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
    for(int i=0; i<100000; i++)
    {
        if(i%100==0)
        {
            cout<<"Running iteration "<<i<<'\n';
            cout<<"Current cost is "<<j(x, w, y, b)<<'\n';
        }
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

void printParams(vector<float>&params)
{
    for(int i=0; i<params.size(); i++)
    {
        cout<<params[i]<<"  ";
    }
    cout<<'\n';
}

int main()
{
    int m, n;
    cout<<"How many training examples?\n";
    cin>>m;
    cout<<"How many features?\n";
    cin>>n;
    cout<<"Enter the examples in the form [x1 x2 x3 .... xn y]\n";
    vector<vector<float>>x(m, vector<float>(n));
    vector<float>y(m);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>x[i][j];
        }
        cin>>y[i];
    }
    vector<float>params = gradDesc(x, y);
    printParams(params);
}
