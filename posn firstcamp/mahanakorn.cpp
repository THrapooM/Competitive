#include<bits/stdc++.h>
using namespace std;
char s[260];
int main()
{
 char a[4][4] = {'5','6','3','4','1','7','2','8','9','5','1','3','2','1','4','6'};
 char a1[4][4] = {'5','6','3','4','1','7','2','8','9','5','1','3','2','1','4','6'};
 int i,j;
    scanf("%s",s);
    int z;
    z = strlen(s);
    int x;
    int b;
    int c;
    for(i=0;i<z;i+=2)
    {
        if(s[i]=='U')
        {
        for(x=0;x<4;x++)
        {
            a1[x][s[i+1]-'1']=a[(x+1)%4][s[i+1]-'1'];
        }
        }
        else if(s[i]=='D')
        {
        for(x=0;x<4;x++)
            a1[x][s[i+1]-'1']=a[(x+3)%4][s[i+1]-'1'];
        }
        else if(s[i]=='L')
        {
            for(x=0;x<4;x++)
                a1[s[i+1]-'1'][x]=a[s[i+1]-'1'][(x+1)%4];
        }
        else if(s[i]=='R')
        {
            for(x=0;x<4;x++)
                a1[s[i+1]-'1'][x]=a[s[i+1]-'1'][(x+3)%4];
        }
        for(x=0;x<4;x++)
        {
            for(c=0;c<4;c++)
            {
                a[x][c] = a1[x][c];
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
        printf("%c",a1[i][j]);
        }
        printf("\n");
    }
}
