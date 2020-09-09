#include <stdio.h>

int table [10000][10000];
int main()
{
    int N;
    scanf("%d",&N);
    int i,n[N],hmax=0,len=0;
    for(i=0; i<N; i++)
    {
        scanf("%d",&n[i]);
        len+=(2*n[i]-1);
        if(n[i]>hmax)
            hmax=n[i];
    }
    int j,k,col=0,total=0,lim=0;
    for(i=0; i<N; i++)
    {
        col=(2*n[i]-1)/2+total;
        for(k=n[i]-1;k>=0;k--)
        {
        for(j=0; j<(2*n[i]-1); j++)
        {
            if(lim==0)
            {
                table[hmax-1-k][col+lim]=2;
            }
            else
            {
                table[hmax-1-k][col+lim]=1;
                table[hmax-1-k][col-lim]=1;
            }
        }
        lim++;
        }
        lim=0;
        total+=2*n[i]-1;    //-1????
    }
    int count=2;
    for(i=0; i<hmax; i++)
    {
        for(j=0; j<len; j++)
        {
            if(table[i][j]==2)
            {
                printf("*");
                continue;
            }
            else if(table[i][j]==1 && count!=1)
            {
                count=1;
            }
            else if(table[i][j]==1 && count==1)
            {
                count=0;
                printf("*");
                continue;
                //count2=1;
            }
            if(count==1)
            {
                printf("*");
            }
            else if(count==0 || count==2 )//&& count2==0)
                printf(".");
        }
        printf("\n");
    }
}
