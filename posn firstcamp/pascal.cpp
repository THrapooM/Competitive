#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
    int f,k;
    scanf("%d %d",&f,&k);
    a[0][0]=f;
    int i,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {   a[i][j]=f;
                continue;
            }
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    int z;
    for(i=0;i<k;i++)
    {
        for(z=0;z<k-i;z++)
        {
            printf("      ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%12d",a[i][j]);
        }
        printf("\n");
    }

}
