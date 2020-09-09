#include<bits/stdc++.h>
using namespace std;
string a[100],a1[100];
int b[5][5],sum[5],sum1[5],sum2[5];
int mem[5];
int main()
{
    int i,j,z;
    for(i=0;i<4;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&b[i][j]);
                sum[i] += b[i][j];
                sum1[j] += b[j][i];
            }
        }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
           {
               if(i==j) continue;
            if(b[i][j]>b[j][i]) mem[i]+=3;
            else if(b[i][j]==b[j][i]) mem[i]+=1;
            else mem[i]+=0;
           }
    }
    for(z=0;z<4;z++)
    {
        sum2[z] = sum[z]-sum1[z];
    }
    int temp;
    for(z=0;z<4;z++)
    {
        for(j=0;j<4;j++)
        {
            if(mem[j]<mem[j+1])
            {
                temp = mem[j];
                mem[j] = mem[j+1];
                mem[j+1] = temp;
            }
        }
    }
    for(i=0;i<4;i++)
    {
        printf("%s %d",a[i],mem[i]);
        printf("\n");
    }
}
