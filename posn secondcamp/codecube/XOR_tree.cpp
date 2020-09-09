#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2,val,tx,tval;
struct axis{
    int x,val;
}t;
vector<axis>from[100005];
int mem[100005];
bool visited[100005];
void dfs(int st,int val){
    mem[st] = val;
    visited[st] = true;
    for(int i=0;i<from[st].size();i++){
         tx = from[st][i].x;
         tval = from[st][i].val;
        if(visited[tx]) continue;
        mem[tx] = mem[st]^tval;
        dfs(tx,mem[tx]);
    }
}
int main(){
    scanf("%d%d",&V,&E);
    for(i=0;i<V-1;i++){
        scanf("%d%d%d",&t1,&t2,&val);
        from[t1].push_back({t2,val});
        from[t2].push_back({t1,val});
    }
    dfs(1,0);
    for(i=0;i<E;i++){
        scanf("%d%d",&t1,&t2);
        printf("%d\n",mem[t1]^mem[t2]);
    }
   
}