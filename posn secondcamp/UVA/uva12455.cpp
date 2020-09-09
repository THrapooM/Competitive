#include<bits/stdc++.h>
using namespace std;
int i,n,x,k,j,z;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int num[1005]= {};
        scanf("%d",&x);
        num[0] = 1;
        {
            scanf("%d",&z);
            for(i=1; i<=z; i++)
            {
                scanf("%d",&k);
                {
                    for(j=x-k; j>=0; j--)
                    {
                        if(num[j])
                            num[j+k] = 1;
                    }
                }
            }
        }
        if(num[x])
            printf("YES\n");
        else
            printf("NO\n");
    }
}
