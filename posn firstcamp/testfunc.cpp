#include<bits/stdc++.h>
using namespace std;
float summ(int x)
{   float sum=0,i;
    for(i=1;i<=x;i++)
{
    sum = sum+1/i;
}
    return sum;

}
int main()
{       int n;
       scanf("%d",&n);
       printf("%f",summ(n));
}
