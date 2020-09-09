#include<stdio.h>
int a[100],s[100];
int b;
int main()
{
    int d,x;
    scanf("%s",s);
    while(d)
    {
        x = d%10;
        d = d/10;
        a[b] = x;
        b++;
    }
    int i;
    for(i= b-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
}
