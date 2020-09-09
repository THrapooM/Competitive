//https://www.codecube.in.th/task/62
#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,val;
    bool operator < (axis k) const{
    return k.val < val;
    }
}t;
priority_queue<axis>pq;
vector<axis>v[10005];
int V,E,st,fi,gf,gt,mt,lm,t1,t2,t3,i;
bool visited[10005],cnt;
int mem[10005];
int main(){
    fill(&mem[0],&mem[10005],1e9);
    scanf("%d%d",&V,&E);
    scanf("%d%d",&st,&fi);
    scanf("%d%d%d%d",&gf,&gt,&mt,&lm);
    v[gf].push_back({gt,mt});
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        //v[t2].push_back({t1,t3});
    }
    mem[st] = 0;
    pq.push({st,0});
    while(!pq.empty()){
        t = pq.top(); pq.pop();
        //visited[t.x] = true;
        for(i=0;i<v[t.x].size();i++){
                //if(visited[v[t.x][i].x]) continue;
                if(t.x==gf && mem[t.x]<=lm &&!cnt) { cnt = 1;mem[gt] = mem[gf]+mt; pq.push({gt,mem[gt]});}
                else if(t.x==gf && mem[t.x]>lm) continue;
                else if(mem[v[t.x][i].x]>t.val+v[t.x][i].val) {mem[v[t.x][i].x] = t.val+v[t.x][i].val;
                pq.push({v[t.x][i].x,mem[v[t.x][i].x]});}
        }
     }
     printf("%d",mem[fi]);
}
