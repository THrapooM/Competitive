#include<bits/stdc++.h>
using namespace std;
struct node{
        int fi,val;
        bool operator < (node t) const{
            return t.val < val;
        }
};
int i,j,cnt,n,m,t1,t2,t3,sum;
bool visited[200005];
vector<node>v[200005];
priority_queue<node>pq;
int main(){
    while (cin >> n >> m){
        if (!n && !m) return 0;
        sum = cnt = 0;
        for (i=0;i<n;i++) v[i].clear();
        memset(visited,false,sizeof(visited));
        //scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&t1,&t2,&t3);
            sum+=t3;
            v[t1].push_back({t2,t3});
            v[t2].push_back({t1,t3});
        }
        pq.push({0,0});
        while(!pq.empty()){
            node t = pq.top(); pq.pop();
            if(visited[t.fi]) continue;
            visited[t.fi] = true;
            for(i=0;i<v[t.fi].size();i++){
                if(!visited[v[t.fi][i].fi]) pq.push({v[t.fi][i].fi,v[t.fi][i].val});
            }
            cnt += t.val;
        }
        printf("%d\n",sum-cnt);
    }
}
