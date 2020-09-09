#include<bits/stdc++.h>
using namespace std;
long long int a[6000005],tmp=1e9,maxx;
int i,n,k,t1,j;
int main()
{
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i] += a[i-1];
    }
    for(i=1;i<=k;i++){
        for(j=i;j<=n;j++){
            if(a[j]-a[j-i]>maxx){
                maxx = a[j]-a[j-i];
                tmp = i;
            }
        }
    }
    if(!maxx) {printf("0\n0");return 0;}
 cout << maxx << endl << tmp;
}
