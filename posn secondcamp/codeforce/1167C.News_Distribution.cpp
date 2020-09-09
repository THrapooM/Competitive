#include<bits/stdc++.h>
using namespace std;
int N,M,k,i,j,x,rnk[500005],h[500005],che,t1,t2;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
int main(){
    scanf("%d%d",&N,&M);
    for(i = 1 ; i <= N ; i++) rnk[i] = 1,h[i] = i;
    for(i = 1 ; i <= M ; i++){
        scanf("%d",&k);
        che = -1;
        for(j = 1 ; j <= k ; j++){
            scanf("%d",&x);
            if(che!=-1){
                t1 = head(x),t2 = head(che);
                if(t1==t2) continue;
               if(rnk[t1] < rnk[t2]) rnk[t2] += rnk[t1],h[t1] = t2;
               else rnk[t1] += rnk[t2],h[t2] = t1;
            }
            che = x;
        }
    }
    for(i = 1 ; i <= N ; i++) printf("%d ",rnk[head(i)]);
}