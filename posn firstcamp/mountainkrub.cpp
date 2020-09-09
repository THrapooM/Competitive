#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int mou[100];
int sum,coun;
int main()
{
    int n,i,j,x=0;
    scanf("%d",&n);
    int max=-9999;
    for(i=0;i<n;i++)
    {
        scanf("%d",&mou[i]);
            sum += mou[i];
            if(max<mou[i])
            {
                max = mou[i];
            }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<mou[i]*2;j++)
        {
            if(j<mou[i])
            {
                a[x][coun]='\\';
                x++;
            }
            else if(j>=mou[i])
            {
                x--;
                a[x][coun]='/';
            }
            coun++;
        }
    }
    for(i=0;i<max;i++)
    {
        for(j=0;j<sum*2;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
