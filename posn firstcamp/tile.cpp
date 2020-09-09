#include<bits/stdc++.h>
using namespace std;
char s[100];
int i,j,k,n;
int main()
{
    /*tile input string width length*/
    int z=0,x=0;
    int b=0;
    scanf("%s",s);
    b = strlen(s);
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==0) x=i;
            printf("%c",s[x]);
            x++;
            if(x==b)
            x=0;
        }
        printf("\n");
    }
}
