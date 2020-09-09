#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100][100];
    char s[20];
    scanf("%s",s);
    int x;
    x = strlen(s);
    int r,c,z=0,j=0,k=0;
    for(r=0;r<1;r++)
    {
    for(c=1;c<=4*x+1;c++)
            {
                if(c%4==3 &&r==0&&j==2)
                    {
                    printf("*");
                    j=0;
                    }
                else if(c%4==3 &&r==0)
                    {
                    printf("#");
                    j++;
                    }
                    else printf(".");
            }
            printf("\n");
    }
    for(r=1;r<2;r++)
    {
    for(c=1;c<=4*x+1;c++)
            {
               if(c%2==0 &&r==1 &&(k==4||k==5))
                  {printf("*");
                    k++;
                    if(k==6) k=0;
                    }
                else if(c%2==0 &&r==1)
                  {printf("#");
                    k++;
                    }
                    else printf(".");
            }
            printf("\n");
    }
    int d=1;
    for(r=2;r<3;r++)
    {
        for(c=1;c<=4*x;c++)
        {
            if(c%4==3)
            {
                printf("%c",s[z]);
                z++;
            }
            else if(c%4==1 )
            {
                if(c==1) printf("#");
                else if(c%12==9||c%12==1) printf("*");
                else printf("#");
            }
            else printf(".");

        }
        if(x%3==0) printf("*");
        else printf("#");
        printf("\n");
    }
    j=0;
    k=0;
    for(r=3;r<4;r++)
    {
    for(c=1;c<=4*x+1;c++)
            {
               if(c%2==0 &&r==3 &&(k==4||k==5))
                  {printf("*");
                    k++;
                    if(k==6) k=0;
                    }
                else if(c%2==0 &&r==3)
                  {printf("#");
                    k++;
                    }
                    else printf(".");
            }
            printf("\n");
    }
    for(r=4;r<5;r++)
    {
    for(c=1;c<=4*x+1;c++)
            {
                if(c%4==3 &&r==4&&j==2)
                    {
                    printf("*");
                    j=0;
                    }
                else if(c%4==3 &&r==4)
                    {
                    printf("#");
                    j++;
                    }
                    else printf(".");
            }
            printf("\n");
    }
}


