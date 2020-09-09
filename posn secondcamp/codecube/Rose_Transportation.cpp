#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int V,E,i,t1,t2;
struct axis{
    int x,y,val;
    bool operator < (axis k) const {
        return k.val > val;
    }
}t;
priority_queue<axis>heap;
int a[N],h[N],rnk[N],u,v,val;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
int main(){
    scanf("%d%d",&V,&E);
    for(i=1;i<=V;i++){
        scanf("%d",&a[i]);
        h[i] = i;
        rnk[i] = 1;
    }
        for(i=1;i<=E;i++){
            scanf("%d%d",&t1,&t2);
            heap.push({t1,t2,a[t1]+a[t2]});
        }
        while(!heap.empty()){
            t = heap.top(); heap.pop();
            u = head(t.x),v = head(t.y);
            if(u==v) continue;
            if(rnk[u]>rnk[v]){
                rnk[u] += rnk[v];
                h[v] = u;
                val += a[t.x];
                val += a[t.y];
            }
            else {
                rnk[v] += rnk[u];
                h[u] = v;
                val += a[t.x];
                val += a[t.y];
            }
        }
        printf("%d",val);


}