#include<bits/stdc++.h>
int main()
{
    long long gcd,n,i,j=1;
    scanf("%lld",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    gcd = arr[0];
    while(j<n)
    {
        if(arr[j]%gcd==0)
            {
                j++;
            }
        else
        {
            gcd = arr[j]%gcd;
        }
    }
    printf("%d",gcd);
    //printf("%d\n",gcd);
    long long k,x=0,z=0;
    for(z=0;z<n;z++)
    {
        k = arr[z]/gcd;
        x +=k;
    }
    printf("%lld",x);


}
