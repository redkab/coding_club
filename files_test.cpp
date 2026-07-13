#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

void printFile(string n)
{
    ifstream file(n);

    if(!file)cout<<"Error\n";

    string line;
    while(getline(file, line))cout<<line<<endl;
}

int main()
{
    string n = "age_filled_test_set_filled.csv";
    printFile(n);
    return 0;
}
