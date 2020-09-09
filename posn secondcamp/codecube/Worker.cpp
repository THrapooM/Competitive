#include<bits/stdc++.h>
using namespace std;
int i,t1,u,v,N,j;
struct axis{
    int x,y,val;
    bool operator < (axis k) const{
        return k.val < val;
    }
}t;
priority_queue<axis>heap;
int rnk[1005],h[1005],a[1005];
long long val;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
int main(){
    scanf("%d",&N);
    rnk[N+1] = 1;
    for(i=1;i<=N;i++){
        h[i] = i;
        rnk[i] = 1;
        scanf("%d",&t1);
        heap.push({i,N+1,t1});
    }
    for(i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            heap.push({i,j,a[i]+a[j]});
        }
    }
    while(!heap.empty()){
        t = heap.top();     heap.pop();
        u = head(t.x),v = head(t.y);
        if(u==v) continue;
        if(rnk[u]>rnk[v]){
            rnk[u] += rnk[v];
            h[v] = u;
        }
        else {
            rnk[v] += rnk[u];
            h[u] = v;
        }
        val += t.val;
    }
    printf("%lld",val);

}