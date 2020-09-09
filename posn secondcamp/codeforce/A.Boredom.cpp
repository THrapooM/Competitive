#include<bits/stdc++.h>
using namespace std;
int N,i,t1,maxx=-1e9;
long long sum[100005],arr[100005];
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&t1);
        arr[t1]+=t1;
        maxx = max(maxx,t1);
    }
    for(i=1 ; i <=maxx ; i++){
    sum[i] = max(sum[i-1],sum[max(0,i-2)]+arr[i]);
    }
    printf("%lld",sum[maxx]);
}