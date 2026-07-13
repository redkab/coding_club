#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

void addLine(string line, vector<vector<string>>&v)
{
    vector<string>tokens;
    string x;
    stringstream ss(line);

    while(getline(ss, x, ','))
    {
        tokens.push_back(x);
    }
    v.push_back(tokens);
}

void numGender(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {   
        if(v[i][1] == "female")v[i][2] = "1";
        else v[i][2] = "0";
    }   
}

void numEmbark(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i][7] == "C")v[i][7] = "1";
        if(v[i][7] == "Q")v[i][7] = "2";
        if(v[i][7] == "S")v[i][7] = "3";
    }
}      

vector<vector<string>>readFile(string name)
{
    ifstream file(name);
    vector<vector<string>>v;
    string line;

    while(getline(file, line))
    {
        addLine(line, v);
    }
    return v;
}

void removeId(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        //v[i].pop_front();
    }
}

void printVec(vector<vector<string>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void printVec(vector<vector<float>>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
}

vector<vector<float>>toNums(vector<vector<string>>&v)
{
    int n = v.size(), m = v[0].size();
    vector<vector<float>>nums(n, vector<float>(m));
    for(int i=0; i<v.size(); i++)
    {
        for(int j=1; j<=6; j++)
        {
            nums[i][j] = stof(v[i][j]);
        }
    }
    return nums;
}

vector<float>params = {0, -0.0482032,   0.498119,   -0.000677717,   -0.043312,   -0.0106833,   0.00173432,   0.216716};
bool predict(vector<float>&ex)
{
    float sum=0;
    for(int i=1; i<=6; i++)
    {
        sum += ex[i]*params[i];
    }

    float g = sum + params[7];
    return g>=0;
}


int main()
{
    string f = "age_filled_test_set_filled.csv";
    vector<vector<string>>v = readFile(f);
    numGender(v);
    ofstream of("predictions.csv");
    if(!of.is_open())cout<<"Error\n";
    of<<"PassengerId, Survived\n";

    vector<vector<float>>nums = toNums(v);
    for(int i=0; i<v.size(); i++)
    {
        of<<v[i][0]<<','<<predict(nums[i])<<'\n';
    }
    of.close();

}

