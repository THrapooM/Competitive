#include<bits/stdc++.h>
using namespace std;
int N,Q,i,a[100005],idx,val,limit=1,l,r,t1;
int tree[300005];
char c;
//q mean find rmq between l and r;
//u mean update a[x] = y;
void update(int idx,int val){
    idx += limit;
    tree[idx] += val;
    while(idx>=1){
        idx/=2;
        tree[idx] = min(tree[idx*2],tree[idx*2+1]);
        //printf("%d %d %d\n",tree[idx],idx,val);
    }
}
int rmq(int l,int r){
    int ans = 1e9;
    l += limit;
    r += limit;
    while(l<=r){
        //printf("tree[%d] = %d tree[%d] = %d\n",l,tree[l],r,tree[r]);
        if(l%2==1) ans = min(tree[l++],ans);
        if(r%2==0) ans = min(tree[r--],ans);
        l/=2,r/=2;
    }
    return ans;
}
int main(){
    scanf("%d%d",&N,&Q);
    while(limit<=N) limit*=2;
    for(i=1;i<=N;i++){
    scanf("%d",&t1);
    update(i,t1);
    }
  //  for(i = 1 ; i <= 24 ; i++) printf("tree[%d] = %d\n",i,tree[i]);
    while(Q--){
        scanf(" %c",&c);
        if(c=='u'){
            scanf("%d%d",&idx,&val);
            a[idx] = val; 
            update(idx,val);
        }
        else {
            scanf("%d%d",&l,&r);
            printf("%d\n",rmq(l,r));
        }
    }
}