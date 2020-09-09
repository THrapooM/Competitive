#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[200]={};
    int ccount[128]={};
    scanf("%s",s);
    int x;
    x = strlen(s);
    int i,j;
    for(i=0;i<x;i++)
    {
        ccount[s[i]]++;
    }
    for(i=0;i<128;i++)
    {
        for(j=0;j<ccount[i];j++)
        {
            printf("%c",i);
        }
    }
}
