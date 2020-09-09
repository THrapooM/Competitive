#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int n,i,j,k;
int main()
{
    int z=1,q=0;
    scanf("%d",&n);
    for(i=1;i<n;i+=z)
    {
        z++;
    }
    int x=z;
    for(i=0;i<z;i++)
    {
        for(j=0;j<2*z-1;j++)
        {
             if(i%2==0&&j<z&&i+j>=z-1)
                {
                    x--;
                    a[i][x]=k+65;
                    k++;
                    if(x==z-i-1)
                    x=z;
                    q++;
                }
            else if(i%2!=0&&j>=z-1&&j<=i+z-1)
               {
                a[i][j]=k+65;
                k++;
                q++;
               }
                if(q==n) break;
              if(k==26) k=0;
        }
    }
    for(i=0;i<z;i++)
        {
            for(j=0;j<2*z-1;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
}

