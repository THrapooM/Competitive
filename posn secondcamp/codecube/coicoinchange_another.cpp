#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,m,k,cost[15],i,j;
int mem[1000005],track[1000005],ans=1e9,buy,sell,tbuy,tsell,cnt[1000005];
void cal(int x){
    if(x==0) return;
        cnt[track[x]]++;
        return cal(x-cost[track[x]]);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++){
        scanf("%d",&cost[i]);
    }
    for(i=1;i<=m;i++){
            mem[i] = inf;
        for(j=1;j<=k;j++){
        if(cost[j]>i) continue;
                mem[i] = min(mem[i],1+mem[i-cost[j]]);
                if(mem[i]==1+mem[i-cost[j]]) track[i] = j;
        }
    }
//    for(i=1;i<=m;i++){
//        printf("mem[%d] = %d\n",i,mem[i]);
//    }
//    for(i=1;i<=m;i++){
//        printf("track[%d] = %d\n",i,track[i]);
//    }
    for(i=n;i<=m;i++){
        if(ans>mem[i]+mem[i-n]){
            ans = mem[i]+mem[i-n];
            buy = i;
            sell = i-n;
            tbuy = mem[i];
            tsell = mem[i-n];
        }
    }
    printf("%d %d\n",tbuy,tsell);
    cal(buy);
    for(i=1;i<=k;i++){
        printf("%d ",cnt[i]);
    }
    printf("\n");
    memset(cnt,0,sizeof(cnt));
    cal(sell);
    for(i=1;i<=k;i++){
        printf("%d ",cnt[i]);
    }
}
