#include<bits/stdc++.h>
using namespace std;
int N,Q,i,a[100005],idx,val,limit=1,l,r,t1;
int tree[400020];
char c;
//sum  mean find sum between l and r;
//u mean update tree[x] = y;
void update(int idx,int val){
    idx += limit;
    tree[idx] += val;
    while(idx>=1){
        idx/=2;
        tree[idx] = tree[idx*2]+tree[idx*2+1];
        //printf("tree[%d] = %d val = %d\n",idx,tree[idx],val);
    }   
}
int sum(int l,int r){
    l += limit;
    r += limit;
    int ans =0;
    while(l<=r){
        printf("tree[%d] = %d tree[%d] = %d\n",l,tree[l],r,tree[r]);
        if(l%2==1) ans += tree[l++];
        if(r%2==0) ans += tree[r--];
        l/=2,r/=2;
    }
    return ans;
}
int main(){
    scanf("%d%d",&N,&Q);
    while(limit<=N) limit*=2;
    for(i=0;i<N;i++){
    scanf("%d",&t1);
    update(i+1,t1);
    }
    //for(i=1;i<=N*2-1;i++) printf("%d\n",tree[i]);
    for(i = 1 ; i <= 24 ; i++) printf("tree[%d] = %d\n",i,tree[i]);
    while(Q--){
        scanf(" %c",&c);
        if(c=='u'){
            scanf("%d%d",&idx,&val);
            update(idx,val);
        }
        else {
            scanf("%d%d",&l,&r);
            printf("%d\n",sum(l,r));
        }
    }
}