#include<bits/stdc++.h>
using namespace std;
int N,M,i,x,y,z,h[300005],ans[300005];
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
void disjoint(int l,int r ,int win){
    int cur;
      while(l <= r){
        cur = head(l);
        if(cur==l){
            ans[l] = win;
            h[l] = l+1;
        }
        l = h[l];
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(i = 1; i <= N+1 ; i++) h[i] = i;
    for(i = 1 ; i <= M ; i++){
    scanf("%d%d%d",&x,&y,&z);
    disjoint(x,z-1,z);
    disjoint(z+1,y,z);
    }
    printf("\n");
    for(i =1 ; i <= N ; i++) printf("%d ",ans[i]);

}