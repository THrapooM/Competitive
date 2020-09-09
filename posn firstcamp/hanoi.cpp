#include<bits/stdc++.h>
char a[100][100];
int main()
{
    int n,i,j,x=0;
    int count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            if(i%2==0&&i+j>=n-1&&j<=n-1)
            {
                a[i][n-x-1]= count+65;
                count++;
                x++;
            }
            else if(i%2!=0&&j>=n-1&&j-i<=n-1)
            {
                a[i][j]=count+65;
                count++;
            }
            if(count==26) count =0;
        }
        x=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
