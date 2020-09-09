#include<bits/stdc++.h>
using namespace std;
int  a[100],b[100];
char s[100];
int main()
{
    scanf("%s",s);
    int i,j=0,k=0;
    int x,y=0;
    int z=0,coun;
    x = strlen(s);
    for(i=0;i<x;i++)
    {
        j++;
        if(s[i]>'0'&&s[i]<='9'&&k==0)
       {
        z = s[i]-'0';
        k=1;
       }
        else if(s[i]=='0')
       {
        a[z] += j;
        k=0;
        j=0;
       }
    }
    x=0;
    for(i=1;i<=9;i++)
    {
        if(a[i])
            {
                x++;
            }
    }
    printf("%d\n",x);
    for(i=1;i<=9;i++)
    {
        if(a[i])
           {
            printf("%d %d",i,a[i]);
            printf("\n");
           }
    }
}
