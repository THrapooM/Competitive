#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],i;
long long sum[1000005],val,ans=-1e17;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i] += (long long)(a[i]+sum[i-1]);
    }
    for(i=1;i<=n-m+1;i++){
        ans = max(ans,(long long)(val+sum[i+m-1]-sum[i-1]));
        val += a[i];
        if(val<0) val=0;
    }
    cout << ans ;
}   