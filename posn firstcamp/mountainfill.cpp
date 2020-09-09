#include<bits/stdc++.h>
char a[100][100];
int x[100];
int main()
{
    int i,j,k;
    int n;
    int sum=0,maxx =-99999;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        if(maxx<x[i])
            maxx = x[i];
        sum += x[i]*2-1;
    }
    int z=0;
    for(i=0;i<n;i++)
    {
        for(k=0;k<x[i];k++)
        {
            for(j=0;j<x[i]*2-1;j++)
            {
            if(j<x[i]&&k+j>=x[i]-1)
                a[k+maxx-x[i]][z+j]='*';
            else if(j>x[i]-1&&j-k<=x[i]-1)
                a[k+maxx-x[i]][z+j]='*';
            }
        }
        z+=x[i]*2-1;
    }
    for(i=0;i<maxx;i++)
    {
        for(j=0;j<sum;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
