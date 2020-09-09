#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
string s1,s2;
int main()
{
    int X,Y;
    cin >> X >> Y >> s1 >> s2;
    int i;
    for(i=0;i<=X-Y;i++)
    {
        m[s1.substr(i,Y)]++;
    }
    cout << m[s2];
}
