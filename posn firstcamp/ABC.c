#include<bits/stdc++.h>
using namespace std;
char s[100];
int s1[100];
int main()
{
    int i=0,j,n;
    gets(s);
    j = strlen(s);
    for(i=0;i<j;i++)
    {
        s1[i] = s[i];
    }
    for(i=0;i<j;i++)
    {
        if(s1[i]==' ')
        {   printf(" ");
            continue;
        }
        s1[i]=s1[i]+1;
        s[i] = s1[i];
         printf("%c",s[i]);
    }
}


