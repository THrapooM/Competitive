#include<bits/stdc++.h>
int mem[1000000];
int main()
{
    int i,j,k;
    scanf("%d",&i);
    for(j=2;j<i;j++)
    {
        for(k=2;k*j<=i;k++)
        {
            mem[k*j]=1;
        }
    }
    for(j=2;j<i;j++)
    {
        if(!mem[j])
            printf("%d ",j);
    }
}
