#include<bits/stdc++.h>
using namespace std;
int V,E,t1,t2,t3,i,mem[1005][2],ans1 = 1e9,ans2;
struct axis{
    int x,val,even,i;
    bool operator < (axis k) const{
        return k.val < val;
    }
}t;
vector<axis>v[1005];
priority_queue<axis>pq;
int main(){
    fill(&mem[0][0],&mem[1004][1],1e9);
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3,0,i});
        v[t2].push_back({t1,t3,0,i});
    }
    mem[1][0] = 1;
    pq.push({1,0,0,0});
    while(!pq.empty()){
        t = pq.top(); pq.pop();
        if(t.x==V && t.even==1 && mem[t.x][1]==t.val){
            //cout << t.i << endl;
            ans1 = min(ans1,t.i);
            ans2 = t.val;
        }
        int teven = (t.even+1)%2;
        for(i=0;i<v[t.x].size();i++){
            int tx = v[t.x][i].x;
            int tval = t.val + v[t.x][i].val;
            int ti = max(t.i,v[t.x][i].i);  
            if(mem[tx][teven]>=tval){
                mem[tx][teven] = tval;
                pq.push({tx,tval,teven,ti});
            }
        }
    }
    printf("%d %d",++ans1,ans2);


}