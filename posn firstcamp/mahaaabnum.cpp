#include<bits/stdc++.h>
using namespace std;
int main()
{
    int f,d,i;
    scanf("%d %d",&f,&d);
    int count=0;
    for(i=1;i<=d;i++)
    {
        if((i+f)%7==4&&i%2!=0)
        {
           count+=3;
        }
        else if((i+f)%7==6&&i%2!=0)
        {
            count+=2;
        }
        else count+=5;
    }
   printf("%d",count);
}
