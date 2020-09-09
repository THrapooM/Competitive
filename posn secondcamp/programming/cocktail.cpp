#include<bits/stdc++.h>
using namespace std;
int minn=1e9;
long long cnt,a[100005];
int x,tt,N,i,j;
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&x);
        //maxx = max(maxx,x);
        minn = min(minn,x);
        a[x]++;
    }
    scanf("%d",&tt);
    for(i=minn;i<=tt/2;i++){
        if(a[i]&&a[tt-i])
        {   if(i==tt-i) cnt+=(long long)(a[i]*(a[i]-1))/2;
            else cnt += (long long)(a[i]*a[tt-i]);
        }
}
    printf("%lld",cnt);
}
