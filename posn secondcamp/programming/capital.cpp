//https://programming.in.th/task/rev2_problem.php?pid=1111
#include<bits/stdc++.h>
using namespace std;
int mem[100005];
bool visited[100005];
struct axis{
    int x,val;
    bool operator <(axis k) const{
        return k.val > val;
    }
}t;
int V,E,i,t1,t2,t3,c,maxx=-1e9;
priority_queue<axis>pq;
vector<axis>v[100005];
int main(){

    fill(&mem[0],&mem[100005],-1e9);
    scanf("%d",&V);
    for(i=0;i<V-1;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }

    mem[1] = 0;
    pq.push({1,0});
    while(!pq.empty()){
        t = pq.top(); pq.pop();
        visited[t.x] = true;
        for(i=0;i<v[t.x].size();i++){
                if(visited[v[t.x][i].x]) continue;
            if(mem[v[t.x][i].x]<v[t.x][i].val+mem[t.x]) mem[v[t.x][i].x] =v[t.x][i].val+mem[t.x];
            pq.push({v[t.x][i].x,mem[v[t.x][i].x]});
        }
    }
    for(i=1;i<=V;i++){
        c = max(c,mem[i]);
    }
    printf("%d",c);

}
