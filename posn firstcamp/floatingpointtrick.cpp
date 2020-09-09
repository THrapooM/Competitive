#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    long long s[100]={};
    for(i=0;i<n;i++)
    {
        long long q;
        scanf("%lld",&q);
        long long l =1;
        while(q--)
        {
            l *= 2.0;
        }
        s[i]=l;
    }
    for(i=0;i<n;i++)
    {
        printf("%lld\n",s[i]);
    }


}

