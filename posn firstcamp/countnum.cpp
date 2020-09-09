#include<bits/stdc++.h>
#include<math.h>
using namespace std;
char s[100];
int a[100];
int main()
{
    scanf("%s",s);
    int i;
    i = strlen(s);
    int j,k=0;
    int x=0,z=0;
    for(j=0;j<i;j++)
    {
        z = round(pow(10,i-j-1));
        printf("%d %d",z,s[j]-'0');
        printf("\n");
    }
   for(j=0;j<i;j++)
   {
       k  = s[j]-'0';
       a[k]++;
   }
   for(j=0;j<10;j++)
   {
       if(a[j])
       {
           printf("'%d' %d",j,a[j]);
       printf("\n");
        }
   }

}
