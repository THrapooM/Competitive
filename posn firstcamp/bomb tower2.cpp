#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int main()
{
    long long n,i,j=0,x,z;
    scanf("%lld %lld",&n,&z);
    for(i=2;i<=n;i++)
    {
        for(x=2;x*i<=n;x++)
        {
            arr[i*x]=1;
        }
    }

    for(i=2;i<=n;i++)
    {
        if(arr[i]!=1)
            {
                j++;
            }
    }
    if(j-z<=0)
    {
        printf("0");
    }
    else printf("%lld",j-z);

}

