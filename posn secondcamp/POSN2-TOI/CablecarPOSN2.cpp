#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,val;
    bool operator < (axis k) const{
        return k.val > val;
    }
}t;
int V,E;
vector<axis>from[2505];
priority_queue<axis>heap;
int mem[2505];
bool visited[2505];
int t1,t2,t3,i,st,fi,all,maxx=-1e9,minn;
int main(){
    scanf("%d%d",&V,&E);
    //fill(&mem[0],&mem[2504],1e9);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3-1});
        from[t2].push_back({t1,t3-1});
        maxx = max(maxx,t3);
    }
    scanf("%d%d%d",&st,&fi,&all);
    heap.push({st,int(1e9)});
    mem[st] = 1e9;
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        // if(visited[t.x]) continue;
        // visited[t.x] = true;
        printf("now = %d val = %d\n",t.x,mem[t.x]);
        if(t.x==fi){
             printf("%d",(all-1)/mem[t.x]+1);
            return 0;
        }
        for(i=0;i<from[t.x].size();i++){
            int tx = from[t.x][i].x;
            int tval = from[t.x][i].val;
             minn = min(t.val,tval);
            if(mem[tx]<minn){
                mem[tx] = minn;
                heap.push({tx,mem[tx]});
            }
        }
    }

}