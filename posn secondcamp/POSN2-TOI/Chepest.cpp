#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,val,c,p;
    bool operator < (axis k) const{
        return k.p < p;
    }
}t;
vector<axis>from[1005];
priority_queue<axis>heap;
int V,E,t1,t2,t3,cost[1005],i,j,st,c,fi,COST;
int mem[1005][105];
int main(){
    scanf("%d%d",&V,&E);
    for(i=0;i<V;i++) scanf("%d",&cost[i]);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3});
        from[t2].push_back({t1,t3});
    }
    scanf("%d%d%d",&c,&st,&fi);
    fill(&mem[0][0],&mem[1005][0],1e9);
    mem[st][0] =0;
    heap.push({st,0,0,0});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        if(t.x==fi){
            printf("%d",t.p);
            return 0;
        }
        COST = t.p;
        for(i=t.c;i<=c;i++){
            for(j=0;j<from[t.x].size();j++){
                int tx = from[t.x][j].x;
                int  tval =  from[t.x][j].val;
                if(tval<=i && mem[tx][i-tval]>=COST){
                    mem[tx][i-tval] = COST;
                    heap.push({tx,0,i-tval,mem[tx][i-tval]});
                }
            }
                COST += cost[t.x];      
        }
    }
}