#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2,t3,st[3],fi[3];
bool che[100005];
long long mem[100005],tx,tval,mem2[100005];
struct axis{
    long long x,val;
    bool operator < (axis k) const {
        return k.val < val;
    }
}t;
vector<axis>from[100005];
vector<int>v[100005];
queue<int>que;
priority_queue<axis>heap,nheap;
int main(){
    scanf("%d%d",&V,&E);
    fill(&mem[0],&mem[V+1],1e17);
    fill(&mem2[0],&mem2[V+1],1e17);
    for(i = 1 ; i <= E ;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3});
        from[t2].push_back({t1,t3});
    }   
    for(i = 1 ; i <= 2 ;i++){
        scanf("%d%d",&st[i],&fi[i]);
    }
    che[st[1]] = che[fi[1]] = true;
    mem[st[1]] = 0;
    heap.push({st[1],0});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        for(i = 0 ; i < from[t.x].size() ; i++){
            tx = from[t.x][i].x;
            tval = from[t.x][i].val;
            if(mem[tx] > t.val + tval){
                mem[tx]  = t.val + tval;
                v[tx].clear();
                v[tx].push_back(t.x);
                heap.push({tx,mem[tx]});
            }
            else if(mem[tx] == t.val + tval) v[tx].push_back(t.x);
        }
    }
    que.push(fi[1]);
    while(!que.empty()){
        int f = que.front(); que.pop();
        for(i = 0 ; i < v[f].size() ; i++){
                if(!che[v[f][i]]){ 
                che[v[f][i]] = true;
                que.push(v[f][i]);
                }
        }
    }
    for(i = 1 ; i <= V ; i++) printf("che[%d] = %d\n",i,che[i]);
    mem2[st[2]] = 0;
    nheap.push({st[2],0});
    while(!nheap.empty()){
        t = nheap.top(); nheap.pop();
        for(i = 0 ; i < from[t.x].size(); i++){
                tx = from[t.x][i].x;
                tval = from[t.x][i].val;
                if(t.val + tval < mem2[tx] && !che[tx]){
                    mem2[tx] = t.val+tval;
                    nheap.push({tx,mem2[tx]});
                }
        }
    }
    if(mem2[fi[2]]==1e17) mem2[fi[2]] = -1;
    printf("%lld",mem2[fi[2]]);
}