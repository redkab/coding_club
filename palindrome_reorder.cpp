#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool canPal(string s, vector<int>&v)
{
    for(char c:s)
    {
        v[c-'A']++;
    }
    int oc=0;

    for(int i=0; i<26; i++)
    {
        if(v[i]%2)oc++;
    }

    if((s.length()%2==0 && oc==0) || (s.length()%2==1 && oc==1))return 1;
    else return 0;
}

string makePal(vector<int>&v)
{
    stack<char>s;
    string ans;
    char mid = '\0';
    //cout<<"Mid is "<<mid<<endl;
    for(int i=0; i<26; i++)
    {
        //cout<<i<<" and v[i] is "<<v[i]<<endl;
        if(v[i])
        {
            if((v[i])%2==1)
            {
                mid = i + 'A';
                v[i] --;
            }
            while(v[i])
            {
                if(!((v[i])%2))
                {
                    ans.push_back(i+'A');
                    //            cout<<"ans is "<<ans<<endl;
                }
                else
                {
                    s.push(i+'A');
                    //              cout<<"pushed "<<i+'A'<<endl;
                }
                v[i]--;
            }
        }
    }
    if(mid)ans.push_back(mid);
    //cout<<"Hals ans is "<<ans<<endl;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


int main()
{
    string s;
    cin>>s;
    vector<int>v(26, 0);

    if(!canPal(s, v))
    {
        cout<<"NO SOLUTION\n";
        return 0;
    }
    cout<<makePal(v)<<endl;
}

