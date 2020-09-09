#include<bits/stdc++.h>
char a[100][100];
int i,j,k;
int main()
{
    int n;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            if(i<n&&(i==j||i+j==2*n-2))
            a[i][j] = i+'A';
            else if(i>=n&&(i==j||i+j==2*n-2))
            {
            a[i][j]=2*n-2-i+'A';
            }
        }
    }
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
