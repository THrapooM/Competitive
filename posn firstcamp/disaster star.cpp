#include<stdio.h>
using namespace std;
int main()
{
    int r,c,i,j,k=0,n,z;
    scanf("%d",&n);
    if(n==1)
        printf("*");
    else if(n!=1)
    {
        for(i=1;i<=n;i++)
    {
        if((2*i)+1==n)
        {
            z = i;
        }
    }
    for(r=1;r<=n/2+1;r++)
    {
        for(c=1;c<=n;c++)
        {

            if((r+c >=z+2) && (r+c<=(2*r)+z))
               {
                   printf("*");
               }
            else printf("-");

        }printf("\n");
    }
    for(r=z;r>=1;r--)
    {
        for(c=1;c<=n;c++)
        {
            if((r+c >=z+2) && (r+c<=(2*r)+z))
               {
                   printf("*");
               }
            else printf("-");
            }printf("\n");
        }
    }
}
