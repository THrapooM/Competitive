#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
string s;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        cin >> s;
        if(!m.count(s))
        {
            printf("OK\n");
            m[s]=1;
        }
        else cout << s << m[s]++ << endl;
    }
}
