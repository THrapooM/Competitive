#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z=0;
    scanf("%d %d",&x,&y);
    int r,c;
    for(r=1;r<=x;r++)
    {
        for(c=1;c<=y;c++)
        {
            z++;
            printf("%c",z+64);
            if(z+64>=90)
            {
                z=0;
            }
        }
        printf("\n");
    }
}
