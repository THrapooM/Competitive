#include<bits/stdc++.h>
using namespace std;
int V,E;
struct axis{
    int x,val;
    bool operator < (axis k) const{
        return k.val > val;
    }
}t;
bool visited[200005];
vector<axis>from[200005];
priority_queue<axis>pq;
long long cnt;
int t1,t2,t3,i;
int main(){
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3-1});
        from[t2].push_back({t1,t3-1});
    }
    pq.push({1,0});
    while(!pq.empty()){
        t = pq.top(); pq.pop();
        if(visited[t.x]) continue;
        visited[t.x] = true;
        for(i=0;i<from[t.x].size();i++){
            int tx = from[t.x][i].x;
            if(visited[tx]) continue;
            pq.push({tx,from[t.x][i].val});
        }
        cnt += t.val;
        //cout << cnt << endl;
    }
    printf("%lld",cnt);
}