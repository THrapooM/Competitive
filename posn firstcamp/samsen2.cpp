#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    if(n/1000>=1)
        {
        i = n/1000;
        n = n-i*1000;
        }
      if(n/500>=1)
         {
             j = n/500;
        n = n-j*500;
         }
    if(n/100>=1)
            {
            k = n/100;
            n = n-k*100;
            }
        printf("B1000 = %d\n",i);
        printf("B500 = %d\n",j);
        printf("B100 = %d",k);
}
