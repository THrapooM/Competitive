#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,val,cap,price,used;
    bool operator < (axis k) const{
        return k.price < price;
    }
}t;
int V,E,cost[105],i,j,st,fi,limit,t1,t2,t3,k;
vector<axis>from[105];
bool visited[105][105][2];
priority_queue<axis>heap;   
int main(){
    scanf("%d",&V);
    for(i=1;i<=V;i++) scanf("%d",&cost[i]);
    scanf("%d%d%d",&st,&fi,&limit);
    scanf("%d",&E);
    for(i=1;i<=E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3});
        from[t2].push_back({t1,t3});
    }
    heap.push({st,0,0,0,0});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        //printf("now = %d price = %d cap = %d used = %d\n",t.x,t.price,t.cap,t.used);
        if(t.x==fi&&t.cap==limit){
            printf("%d",t.price);
            return 0;
        }
        if(visited[t.x][t.cap][t.used]) continue; visited[t.x][t.cap][t.used] = true;
       if(t.cap<limit) {
        heap.push({t.x,0,t.cap+1,t.price+cost[t.x],t.used});
           if(!t.used) heap.push({t.x,0,limit,t.price,1});
        
        }
        for(i=0;i<from[t.x].size();i++){
            //cout << t.price << endl;
            int tx = from[t.x][i].x;
            int tval = from[t.x][i].val;
            if(t.cap-tval>=0)
            heap.push({tx,0,t.cap-tval,t.price,t.used});

        }
    }
}