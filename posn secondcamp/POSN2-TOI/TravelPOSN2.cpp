#include<bits/stdc++.h>
using namespace std;
int V,E,t1,t2,t3,st,fi,price,i,j,Cap,dis=-1e9,minn=1e9,dis2;
bool check;
struct axis{
    int x,val,i;
    bool operator < (axis k) const {
      if(k.val!=val) return k.val < val;
         return k.i < i;
    }
}t;
vector<axis>from[10005];
priority_queue<axis>heap,nheap;
int mem[10005],mem1[10005];
int main(){
    fill(&mem[0],&mem[10004],1e9);
    scanf("%d%d",&V,&E);
    scanf("%d%d%d",&st,&fi,&price);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3});
        from[t2].push_back({t1,t3});
    }
    mem[st] = 0;
    heap.push({st,0,st});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        if(t.x==fi){
            if(t.val<=price){
                printf("%d %d %d",fi,t.val,0);
                return 0;
            }
        }
        for(i=0;i<from[t.x].size();i++){
            int tx = from[t.x][i].x;
            int tval = from[t.x][i].val;
            if(mem[tx]>mem[t.x]+tval){
                mem[tx] = mem[t.x]+tval;
                heap.push({tx,mem[tx],tx});
            }
        }
    }
    fill(&mem1[0],&mem1[10004],1e9);
    mem1[fi] = 0;
    nheap.push({fi,0,fi});
    while(!nheap.empty()){
        t = nheap.top(); nheap.pop();
        if(mem[t.x]<=price){ printf("%d %d %d",t.i,mem[t.i],t.val); return 0;}
            for(i=0;i<from[t.x].size();i++){
                int tx = from[t.x][i].x;
                int tval = from[t.x][i].val;
                if(mem1[tx]>mem1[t.x]+tval){
                    mem1[tx] = mem1[t.x]+tval;
                    nheap.push({tx,mem1[tx],tx});
                }
            }
    }
  //  printf("%d %d %d",minn,mem[minn],dis2);


    
}