#include <stdio.h>

int table[10000][10000];

int main(){
int N;
scanf("%d" ,&N);
int i,j,hl=2*N-1,k=N,count=0;
for(i=hl/2;i<hl;i++)
{
        table[i][hl/2+count]=k;
        table[i][hl/2-count]=k;
        k--;
        count++;
}
count=0,k=N;
for(i=hl/2;i>=0;i--)
{
    table[i][hl/2+count]=k;
    table[i][hl/2-count]=k;
    k--;
    count++;
}
for(i=0;i<hl;i++)
{
    for(j=0;j<hl;j++)
    {
    if(table[i][j]!=0)
        {
        printf("%d" ,table[i][j]);
        }
    else if(table[i][j]==0)
        {
            printf(" ");
        }
    }
    printf("\n");
}
}
