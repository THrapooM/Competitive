#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    char arr[x][y];
    int r,c,k=0;
    for(r=0;r<x;r++)
    {
        for(c=0;c<y;c++)
        {
            scanf(" %c",&arr[r][c]);
        }
    }
    for(r=0;r<x;r++)
    {
        for(c=0;c<y;c++)
        {
            if(arr[r][c]=='+')
            {
             arr[r][c]='.';
             arr[r++][c]='.';
             arr[r--][c]='.';
             arr[r][c--]='.';
             arr[r][c++]='.';
            }
        }
    }
    /*for(r=0;r<x;r++)
    {
        for(c=0;c<y;c++)
        {
           if(arr[r][c]=='x')
            {
                arr[r][c]='.';
                arr[r++][c++]='.';
                arr[r+=2][c+=2]='.';
                arr[r++][c--]='.';
                arr[r+=2][c-=2]='.';
                arr[r--][c++]='.';
                arr[r+=2][c+=2]='.';
                arr[r--][c--]='.';
                arr[r-=2][c-=2]='.';
            }
        }
    }*/
    for(r=0;r<x;r++)
    {
        for(c=0;c<y;c++)
        {
            if(arr[r][c]=='A')
               {
                  k++;
               }
            printf("%c",arr[r][c]);
        }
        printf("\n");
    }
    /*printf("%d\n",k);
    for(r=0;r<x;r++)
    {
        for(c=0;c<y;c++)
        {
            printf("%c",arr[r][c]);
        }
        printf("\n");
    }*/

}
