#include<bits/stdc++.h>
using namespace std;
int n,i,tree[100005],a[100005],q,idx,val,st,fi;
char c;
void update(int idx,int val){
    while(idx<=n){
        tree[idx] += val;
        idx += idx&-idx;
    }
}
void before(int idx,int val){
    while(idx<=n){
        tree[idx] -= val;
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
int main(){
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        update(i,a[i]);
    }
    for(i=1;i<=q;i++){
        scanf(" %c",&c);
        if(c=='u'){
            scanf("%d%d",&idx,&val);
            before(idx,a[idx]);
            update(idx,val);
        }
        else {
            scanf("%d%d",&st,&fi);
            printf("%d\n",findsum(fi)-findsum(st-1));
        }
    }
}