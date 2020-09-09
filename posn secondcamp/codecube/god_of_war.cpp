#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2,t3,st,fi,sum,tx,tval;
struct axis{
    int x,val;
    bool cross;
    bool operator < (axis k) const {
        return k.val < val;
    }
}t;
vector<axis>from[100005];
priority_queue<axis>heap;
int mem[100005][3];
int main(){
    scanf("%d%d",&V,&E);
    scanf("%d%d",&st,&fi);
    fill(&mem[0][0],&mem[100004][2],1e9);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3});
        from[t2].push_back({t1,t3});
        sum += t3;
    }
    mem[st][0] = 0;
    heap.push({st,0,0});
    while(!heap.empty()){
        t = heap.top(),heap.pop();
        //printf("t.x = %d val = %d\n",t.x,t.val);
        for(i=0;i<from[t.x].size();i++){
            tx = from[t.x][i].x;
            tval = from[t.x][i].val;
            //printf("mem[%d] = %d tval = %d t.x = %d t.val = %d\n",tx,mem[tx],tval,t.x,t.val);
            if(!t.cross&&t.val<mem[tx][1]){
                mem[tx][1] = t.val;
                heap.push({tx,mem[tx][1],1});
            }
            if(t.val+tval<mem[tx][t.cross]){
                mem[tx][t.cross] = t.val + tval;
                heap.push({tx,mem[tx][t.cross],t.cross});
            }
        }
    }
   // printf("%d",mem[fi][1]);
    //printf("%d",sum-mem[fi]+valmax[fi]);
    printf("%d",sum-mem[fi][1]);
        

}