#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,i,j,k;
    scanf("%ld %ld",&n,&i);
    char s[1005];
    scanf("%s",s);
    char s2[1005];
    scanf("%s",s2);
    j = strlen(s);
    k = strlen(s2);
    long z,g,h=0,x=0;
    for(z=0;z<j;z++)
    {
       for(g=0;g<k;g++)
       {
           if(s2[g]==s[g+z])
           {
               x++;
               continue;
           }
           if(x==k)
           {
               h++;
           }
           if(s2[g]!=s[g+z])
           {
               x=0;

           }
        }

    }
    printf("%ld",h);
    return 0;
}




