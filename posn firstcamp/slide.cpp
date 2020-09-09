#include<bits/stdc++.h>
using namespace std;
char s[100],x,s1[100];
int n,i,j,k;
/*spin side*/
int main()
{
        gets(s);
        k = strlen(s);
        scanf(" %c",&x);
        scanf("%d",&n);
        for(i=0;i<k;i++)
        {
            s1[i] = s[i];
        }
        for(i=0;i<k;i++)
        {
            if(x=='L')
            {
                s1[i] = s[(i+n)%k];
            }
            else if(x=='R')
            {
                s1[i] = s[(i-n+k)%k];
            }
            printf("%c",s1[i]);
        }
}
