#include<bits/stdc++.h>
using namespace std;
int a[2505];
int main()
{
    int n,i,x=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int fm=0,sm=0;
    for(i=0; i<n; i++)
    {
        fm = fm+a[i];
        if(fm<0)
        {
            fm = 0;
        }
        if(sm<fm)
        {
            sm = fm;
        }
    }
    if(sm==0)
    {
        printf("Empty sequence");
        return 0 ;
    }
    int thirdm=0,fourthm=0,check=0,z;
    for(i=0; i<n; i++)
    {
        thirdm = thirdm+a[i];
        if(thirdm<0)
        {
            thirdm = 0;
        }
        if(thirdm<fourthm)
        {
            thirdm = fourthm;
        }
        if(thirdm == sm)
        {
            for(check=i; check>=0; check--)
            {
                thirdm -= a[check];
                if(thirdm==0)
                {
                    for(z=check; z<=i; z++)
                        printf("%d ",a[z]);
                    printf("\n");
                    printf("%d",sm);
                    return 0;
                }
            }
        }
    }
}


