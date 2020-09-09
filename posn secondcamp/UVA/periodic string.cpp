#include<bits/stdc++.h>
using namespace std;
int i,j,n,k;
string s1;
map<string,int>m;
int main()
{
//      freopen("i455.txt","r",stdin);
//    freopen("o455.txt","w",stdout);
    scanf("%d",&n);
    for(k=0; k<n; k++)
    {
        cin >> s1;
        for(i=1; i<=s1.length(); i++)
        {
            j = 0;
            m.clear();
            while(j<s1.size())
            {
                m[s1.substr(j,i)]++;
                j+=i;
            }
            if(m[s1.substr(0,i)]*(i)==s1.length())
            {
                if(k!=n-1)
                    printf("%d\n\n",i);
                else
                    printf("%d\n",i);

                break;
            }

        }
    }
}
