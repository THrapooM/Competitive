#include<stdio.h>
int main()
{
    int n,z=0;
    scanf("%d",&n);
    int a[100]={};
    while(n!=0)
    {
        int c = n%16;
        n = n/16;
        a[z] = c;
        z++;
    }
    int i=0;
    for(i=z-1;i>=0;i--)
    {
        if(a[i]>=10&&a[i]<=15)
        {
                a[i]+=55;
                printf("%c",a[i]);
        }
        if(a[i]<10) printf("%d",a[i]);
    }
}
