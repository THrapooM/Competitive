#include<bits/stdc++.h>
using namespace std;
int N,i,tree[200005],a[200005],idx,nidx;
void update(int idx){
    while(idx<=N){
        tree[idx]--;
        idx += idx&-idx;    
    }
}
int findsum(int idx){
    int sum = 0;
    while(idx>=1){
        sum += tree[idx];
        idx -= idx&-idx;
    }
    return sum;
}   
int query(int idx){
    int l = 1,r = N,mid;
    while(l<=r){
        mid = l+r >> 1;
        if(findsum(mid) >= idx) r = mid-1;
        else l = mid+1;
  //      printf("l = %d r = %d mid = %d findsum(%d) = %d idx = %d\n",l,r,mid,mid,findsum(mid),idx);
    }
    //printf("l = %d r = %d mid = %d\n",l,r,mid);
    return l;
}
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++) tree[i] = i&-i;
  //  for(i=1;i<=N;i++) printf("tree[%d] = %d\n",i,tree[i]);
    for(i=1;i<=N;i++) scanf("%d",&a[i]);
    for(i=1;i<=N;i++){
        scanf("%d",&idx);
        nidx = query(idx);
        printf("%d\n",a[nidx]);
        update(nidx);
     // for(int i=1;i<=N;i++) printf("%d tree[%d] = %d\n",nidx,i,tree[i]);
    }

}