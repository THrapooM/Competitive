#include<bits/stdc++.h>
using namespace std;
char s[100];
int s1[100];
int main()
{
    int i=0,j,n,k;
    gets(s);
    scanf("%d",&k);
    j = strlen(s);
    for(i=0;i<j;i++)
    {
        if(s[i]==' ')
            {printf(" ");
            continue;
            }
       else printf("%c",s[i]+k);
    }
}


