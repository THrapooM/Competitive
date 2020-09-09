#include<bits/stdc++.h>
using namespace std;
int n,i,j,k;
int main()
{   int a[100][100];
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
             if(i<n&&(i==j||i+j==2*n-2))
                a[i][j]=i+1;
            else if(i>=n&&(i+j==2*n-2||i==j))
                a[i][j]=2*n-i-1;

        }
    }
    for(i=0;i<n*2-1;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            if(a[i][j]==0) printf(" ");
           else  printf("%d",a[i][j]);
        }
        printf("\n");
    }

}
