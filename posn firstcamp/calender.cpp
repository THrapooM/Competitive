#include<bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
    int mem[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
        if(a[2]%4==3)
            mem[1]=29;
    }
    int d;
    d = a[0]-1;
    for(i=0;i<a[1]-1;i++)
    {
        d+=mem[i];
    }
    for(i=1;i<a[2];i++)
    {
        d+=365;
        if(i%4==3) d++;
    }
    printf("%d",d);
    d%=7;
    if(d==6) printf("Saturday");
    else if(d==0) printf("Sunday");
    else if(d==1) printf("Monday");
    else if(d==2) printf("Tuesday");
    else if(d==3) printf("Wednesday");
    else if(d==4) printf("Thursday");
    else printf("Friday");
}
