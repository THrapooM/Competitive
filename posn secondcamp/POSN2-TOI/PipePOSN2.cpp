#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,val;
    bool operator < (axis k) const{
        return k.val < val;
    }
}t;
int n,k,i,h[15005],cnt,t1,t2,j;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
vector<axis>from;
priority_queue<axis>heap;
priority_queue<int>pq;
int main(){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
     h[i] = i;
    scanf("%d%d",&t1,&t2);
    from.push_back({t1,t2});
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            heap.push({i,j,abs(from[i].x-from[j].x)+abs(from[i].y-from[j].y)});
        }
    }
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        if(head(t.x)!=head(t.y)){
            h[head(t.x)] = head(t.y);
            cnt += t.val;
            pq.push(t.val);
        }
    }
    for(i=0;i<k-1;i++) {cnt-= pq.top(); pq.pop();}
    cout << cnt;
}