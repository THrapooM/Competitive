#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int sum=1,n,i,j,k,max=-99999;
    int count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum *= a[i];
        if(max<a[i])
            max = a[i];
    }
    for(i=max;i<=sum;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i%a[j]==0)
                count++;
        }
        if(count==n) break;
        count = 0;
    }
    printf("%d",i);
}

