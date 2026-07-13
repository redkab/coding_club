#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

void process(string line, vector<vector<string>>&v)
{
    stringstream ss(line);
    string token;
    vector<string>x;

    while(getline(ss, token, ','))
    {
        if(token == "")x.push_back("-1");
        else x.push_back(token);
    }
    v.push_back(x);
}

void printVec(vector<string>&v)
{
    for(string s:v)
    {
        cout<<s<<' ';
    }
    cout<<'\n';
}

void printVec(vector<float>&v)
{
    for(float s:v)
    {
        cout<<s<<' ';
    }
    cout<<'\n';
}

void printGrid(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        printVec(v[i]);
    }
}

void printGrid(vector<vector<float>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        printVec(v[i]);
    }
}

vector<vector<string>>readFile(string fileName)
{
    vector<vector<string>>v;
    ifstream file(fileName);

    if(!file)
    {
        cout<<"Error\n";
    }

    string line;
    while(getline(file, line))
    {
        process(line, v);
    }
    file.close();
    return v;
}

void numGender(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i][1] == "female")v[i][1] = "1";
        else v[i][1] = "0";
    }
}

void numEmbark(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i][6] == "C")v[i][6] = "1";
        if(v[i][6] == "Q")v[i][6] = "2";
        if(v[i][6] == "S")v[i][6] = "3";
    }
}

vector<vector<float>>strToNum(vector<vector<string>>&v)
{
    int n = v.size();
    cout<<"n in func is "<<n<<endl;
    int m = v[0].size();
    vector<vector<float>>nums(n, vector<float>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            nums[i][j] = stof(v[i][j]);
            cout<<"At "<<i<<' '<<j<<endl;
        }
    }
    return nums;
}

void fillAges(vector<vector<float>>&v)
{
    float sum=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i][2]>0)sum += v[i][2];
    }
    int avg = sum/v.size();

    for(int i=0; i<v.size(); i++)
    {
        if(v[i][2] <0)v[i][2] = (float)avg;
    }
}

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

float f(vector<float>&w, float b, vector<float>&x)
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
    cout<<n<<" features\n";
    vector<float>w(n, 0.0);
    float b=0;
    float a = 0.0001;
    vector<float>temp(n, 0.00);
    for(int i=0; i<100000; i++)
    {
        if(i%1000==0)
        {
            cout<<"Running iteration "<<i<<" and current cost is "<<j(x, w, y, b)<<'\n';
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

bool predict(vector<float>&params, vector<float>&example)
{
    float x=0;
    for(int i=0; i<params.size(); i++)
    {
        x += params[i]*example[i];
    }
    if(x<0)return 0;
    else return 1;
}


int main()
{
    string fn = "filtered_training_set.csv";
    vector<vector<string>>v = readFile(fn);
    numEmbark(v);
    numGender(v);
    //printGrid(v);
    vector<vector<float>>nums = strToNum(v);
    fillAges(nums);
    //printGrid(nums);
    int numFeatures = nums[0].size()-1;
    int numExamples = nums.size();
    vector<float>survived(numExamples);
    for(int i=0; i<numExamples; i++)
    {
        survived[i] = nums[i].back();
        nums[i].pop_back();
    }
    //cout<<"Number of features is "<<nums[0].size()<<'\n';
    vector<float>params = gradDesc(nums, survived);
    printParams(params);
    /*string test_set = "age_filled_test_set_filled.csv";
    vector<vector<string>>out = readFile(test_set);
    numEmbark(out);
    numGender(out);
    cout<<"n main is "<<out.size();
    vector<vector<float>>test_nums = strToNum(out);
    fillAges(test_nums);
    for(int i=0; i<10; i++)
    {
        //cout<<predict(params, test_nums[i])<<endl;
    }*/


    return 0;
}

