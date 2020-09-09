#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
string w1,w2;
int WL1,WL2;
int main()
{
    int i;
    while(cin >> w1 >> w2)
    {
        WL1 = w1.length();
        WL2 = w2.length();
        for(i=0;i<=WL1-WL2;i++)
        {
            m[w1.substr(i,WL2)]++;
        }
       cout << m[w2];
    }
}
