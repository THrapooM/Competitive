#include<bits/stdc++.h>
using namespace std;
int a[100005],h[100005];
struct axis{
    int x,y,val;
    bool operator < (axis k) const{
    return k.val < val;
    }
}t;
priority_queue<axis>pq;
int n,m,i,t1,t2,cnt;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        pq.push({t1,t2,a[t1]+a[t2]});
    }
    for(i=1;i<=n;i++) h[i] = i;
    while(!pq.empty()){
        t = pq.top(); pq.pop();
            if(head(t.x)!=head(t.y)){
                h[head(t.x)] = head(t.y);
                cnt += t.val;
            }
    }
    printf("%d",cnt);
}
