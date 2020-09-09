#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[1000005],mn=1e9,track[1000005],cnt[1000005];
int val,lm,n,i,cost[15],j,buy,ton,cbuy,cton;
void cal(int x){
    if(x==0) return;
    cnt[track[x]]++;
    cal(x-cost[track[x]]);
}
int main(){
    scanf("%d%d%d",&val,&lm,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    for(i=1;i<=lm;i++)
    {
        mem[i] = inf;
        for(j=1;j<=n;j++){
            if(cost[j]>i) continue;
                mem[i] = min(mem[i],1+mem[i-cost[j]]);
                if(mem[i]==1+mem[i-cost[j]]) track[i] = j;
        }
    }
//     for(i=0;i<=lm;i++){
//        printf("mem[%d] = %d\n",i,mem[i]);
//    }

    for(i=val;i<=lm;i++){
        if(mem[i]+mem[i-val]<mn){
            mn = mem[i]+mem[i-val];
            buy  = mem[i];
            ton  = mem[i-val];
            cbuy   = i;
            cton   = i-val;
        }
    }
    printf("%d %d\n",mem[buy],mem[ton]);
//    for(i=1;i<=lm;i++){
//        printf("track[%d] = %d\n",i,track[i]);
//    }
    cal(cbuy);
    for(i=1;i<=n;i++){
    printf("%d ",cnt[i]);
    }
    printf("\n");
    memset(cnt,0,sizeof(mem));
    cal(cton);
    for(i=1;i<=n;i++){
        printf("%d ",cnt[i]);
    }
}

