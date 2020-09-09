#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100],s1[100];
    int a[100],a1[100];
    scanf("%s",s);
    scanf("%s",s1);
    int i=strlen(s);
    int i1=strlen(s1);
    int sum=0,sum1=0;
    int z;
    for(z=0;z<i;z++)
    {
       if(s[z]>='A'&&s[z]<='F')
       {
           s[z] = s[z]-'A'+10;
       }
       else s[z]=s[z]-'0';
        sum +=(s[z]*pow(16,i-z-1));
    }
    //printf("%d",sum);
    for(z=0;z<i1;z++)
    {
         if(s1[z]>='A'&&s1[z]<='F')
       {
           s1[z] = s1[z]-'A'+10;
       }
       else s1[z]=s1[z]-'0';
        sum1 +=(s1[z]*pow(16,i1-z-1));
    }
    //printf("%d",sum1);
    sum = sum+sum1;
    int a2[100];
    int x=0;
    while(sum!=0)
    {
        z = sum%16;
        sum = sum/16;
        a2[x] = z;
        x++;
    }
    for(i=x-1;i>=0;i--)
    {
        if(a2[i]>=10&&a2[i]<=15)
        {
            printf("%c",a2[i]+'A'-10);
        }
        else printf("%d",a2[i]);
    }
}
