#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[100][100];
int c[100][100];
int main()
{
    int i,j,k;
    int n,n1;
    int x,x1;
    scanf("%d %d",&n,&n1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&x,&x1);
    for(i=0;i<x;i++)
    {
        for(j=0;j<x1;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if(n1!=x)
    {
        printf("error");
        return 0;
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<x1;j++)
        {
            for(k=0;k<x;k++)
            {
                sum = sum+a[i][k]*b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<x1;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}
