#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    int i,j,k[105],k1[105],k2[105];
    scanf("%d %d",&m,&n);
    int A[1000],B[1000];
    for(i=0;i<m;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    {
      scanf("%d",&B[i]);
    }
    int z=0;
    for(j=0;j<m;j++)
    {
        for(i=j+1;i<=m-1;i++)
        {
                k[z] = A[j] + A[i];
                z++;
        }
    }
   int min1 = k[0];
    for(i=0;i<z;i++)
    {
        if(min1>k[i])
        min1 = k[i];
    }
    int x=0;
    for(j=0;j<n;j++)
    {
        for(i=j+1;i<=n-1;i++)
        {
                k1[x] = B[j] + B[i];
                x++;
        }
    }
    int min2 = k1[0];
    for(i=0;i<x;i++)
        {
            if(min2>k1[i])
            min2 = k1[i];
        }
        int y=0;

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                k2[y] = A[i] + B[j] + 100;
                y++;
            }
        }
        int min3 =k2[0];
        for(i=0;i<y;i++)
        {
            if(min3>k2[i])
                min3 = k2[i];
        }
        //printf("%d",min3);
        if(min1>min2)
        {
            if(min2>min3)
            {
                printf("%d",min3);
            }
            else printf("%d",min2);
        }
        if(min1<min2)
        {
            if(min1>min3)
            {
                printf("%d",min3);
            }
            else printf("%d",min1);
        }
        return 0;




}
