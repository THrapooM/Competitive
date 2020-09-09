#include<stdio.h>
int main()
{
    int i,j,k,n;
    int mem[105][105],count=1;
    scanf("%d",&n);
    for(i=0;i<=2*n;i++)
    {
        for(j=0;j<=i&&j<n;j++)
        {
            k = i-j;
            if(k>=0&&k<n) mem[j][k]=count++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
}
