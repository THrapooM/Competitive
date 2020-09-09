#include<bits/stdc++.h>
using namespace std;
char s[100],s1[100];
int main()
{
    scanf("%s",s);
    int i,j,k=0,x;
    x = strlen(s);
    scanf("%s",s1);
    int z;
    z = strlen(s1);
    int m=0;
    for(i=0;i<x;i++)
    {
      for(j=0;j<z;j++)
      {
          if(s1[j]==s[i+j])
          {
              k++;
              if(k==z) m++;
          }
    }
     k=0;
    }
    printf("%d",m);
}
