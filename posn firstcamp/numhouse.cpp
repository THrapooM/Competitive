#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int j,k,i;
    for(i=n;i<=x;i++)
    {
        j = i;
        while(j!=0)
        {
            k = j%10;
            j = j/10;
            a[k]+=1;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d %d",i,a[i]);
        printf("\n");
    }
}
