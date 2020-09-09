#include<bits/stdc++.h>
using namespace std;
int i,V,E;
int h[200005],t1,t2,t3,rnk[200005],u,v;
long long cnt;
struct axis{
    int x,y,val;
    bool operator < (axis k) const{
        return k.val > val;
    }
}t;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
priority_queue<axis>heap;
int main(){
        scanf("%d%d",&V,&E);
        for(i=0;i<E;i++){
            scanf("%d%d%d",&t1,&t2,&t3);
            heap.push({t1,t2,t3-1});
        }
       // cout << 2;
       for(i=1;i<=V;i++) h[i] = i,rnk[i] = 1;
        while(!heap.empty()){
            t = heap.top(); heap.pop();
            u = head(t.x), v = head(t.y);
            if(u==v) continue;
            if(rnk[u]>rnk[v]){
                rnk[u] += rnk[v];
                h[v] = u;
            }
            else{
                rnk[v] += rnk[u];
                h[u] = v;
            }
            cnt += t.val;
        }
        printf("%lld",cnt);
}