#include<bits/stdc++.h>
using namespace std;
int V,E,K,city[20],t1,t2,t3,i,j,k,check = 0,minn = 1e9;
int dis[205][205],mem[20][40005];
int dfs(int now,int che){
    if(now == K+2 && che == check) return 0;
    else if(now == K+2 && che != check) return 1e9;
    else if(mem[now][che]==1e9){
        for(int i = 2;i <= K+2 ; i++){
            if(((1<<(i-1)&che)==0)){
                mem[now][che] = min(mem[now][che],dfs(i,che|(1<<(i-1)))+dis[city[now]][city[i]]);
            }
        }
    }
    return mem[now][che];
}
int main(){
    scanf("%d%d%d",&V,&E,&K);
    city[1] = 1;
    city[K+2] = V;
    check = (1 << (K+2))-2;
    for(i=2;i<=K+1;i++){
        scanf("%d",&t1);
        city[i] = t1;
    }
    fill(&dis[0][0],&dis[204][204],1e9);
    for(i=1;i<=E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        dis[t1][t2] = t3;
        dis[t2][t1] = t3;
        dis[t1][t1] = 0;
        dis[t2][t2] = 0;
    }
    for(i = 1; i <= V ; i++)
        for(j = 1; j <= V; j++)
            for(k = 1; k <= V; k++)
            dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
    fill(&mem[0][0],&mem[19][40005],1e9);
    printf("%d",dfs(1,0));
}