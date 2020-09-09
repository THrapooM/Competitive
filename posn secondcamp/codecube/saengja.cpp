#include<bits/stdc++.h>
using namespace std;
#define inf 1e18;
int N,K,i;
struct axis{
    int x;
    long long y;
    bool operator < (axis k) const{
        return k.x > x;
    }
}t,a[100005];
struct axis2{
    int x; long long y;
    bool operator < (axis2 k) const{
        return k.y > y;
    }
};
priority_queue<axis2>heap;
long long pos[100005],suk[100005],dp[100005],pus,add;
int main(){
    scanf("%d%d",&N,&K);
    for(i = 1 ; i <= N ; i++){
        scanf("%d%lld",&a[i].x,&a[i].y);
   }  
    sort(a+1,a+N+1);
    for(i = 1 ; i <= N ; i++){
        pos[i] = a[i].x;
        suk[i] = a[i].y;
    }
    for(i = 1 ; i <= N ;i++){
        while(!heap.empty() && pos[i] - pos[heap.top().x] > K) heap.pop();
        if(heap.empty()) {pus = -inf;}
        else {pus = heap.top().y;}
        dp[i] = max(dp[i-1],suk[i]-pos[i]+pus);
        add = suk[i]+pos[i]+dp[i-1];
        heap.push({i,add});
    }
    printf("%lld",dp[N]);
}