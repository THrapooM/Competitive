#include<bits/stdc++.h>
using namespace std;
char s[100],s2[100];
int main()
{
    scanf("%s",s);
    scanf("%s",s2);
    int x = strlen(s);
    int y = strlen(s2);
    int i,j,c,d;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(s[i]==s2[j])
                {
                    c=i;
                    d=j;
                }
        }
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(i==d) printf("%c",s[j]);
            else if(j==c) printf("%c",s2[i]);
            else printf(" ");
        }
        printf("\n");
    }
}
