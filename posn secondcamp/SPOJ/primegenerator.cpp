#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
long long mem[100000005];
int main()
{
    long long n;
    long long n1,n2;
    scanf("%lld",&n);
    long long i,j,k;
    v.push_back(2);
    int z;
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&n1,&n2);
        for(j=n1;j<=n2;j++)
        {
            for(k=0;k<v.size();k++)
            {
                if(mem[j]==1) break;
                if(j%v[k]==0&&j!=2&&j!=v[k])
                {
                mem[j] = 1;
                }
            }
            if(!mem[j]&&j!=1) {printf("%lld\n",j);
               v.push_back(j); }
        }
        printf("\n");
    }
}


