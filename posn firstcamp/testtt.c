#include<stdio.h>
int main()
{
    int i,j,k=0;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>=i)
            {
                k++;
                printf("%d",k);
            }
            else printf(" ");
        }
        k=0;
        printf("\n");
    }
}
