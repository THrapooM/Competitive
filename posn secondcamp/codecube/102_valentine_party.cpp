#include<bits/stdc++.h>
using namespace std;
int N,K,i,j,k,mid,lr,dmg,que,num,tmp;
int tree[1000005];
void update(int idx,int val){
    while(idx <= N){
        tree[idx] += val;
        idx += idx&-idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx >= 1){
        sum += tree[idx];
        idx -= idx&-idx;
    }
    return sum;
}
// void check(){
//     for(int i = 1 ; i <= N ; i++)
//         printf("tree[%d] = %d\n",i,tree[i]);
// }
int main(){
    scanf("%d%d",&N,&K);
    for(i = 1 ; i <= K ; i++){
        scanf("%d%d%d%d",&mid,&lr,&dmg,&que);
        if(mid + lr > N){
            update(1,dmg);
            update(mid-lr,dmg);
            update(mid+lr-N+1,-dmg);
        }
        else if(mid - lr < 1){
            update(1,dmg);
            update(N+mid-lr,dmg);
            update(mid+lr+1,-dmg);
        }
        else {
            update(mid-lr,dmg);
            update(mid+lr+1,-dmg);
        }
        //for(k = 1 ; k <= N ; k++) printf("val[%d] = %d ",k,query(k));
        for(j = 1 ; j <= que ; j++){
            scanf("%d",&num);
            tmp = query(num);
            if(10000 - tmp <= 0) printf("0 ");
            else printf("%d ",10000-tmp);
        }
        printf("\n");
    }
}