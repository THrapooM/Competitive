#include <bits/stdc++.h>
using namespace std;
int N,M,Q,H,s,e,t1,t2,t3,tx,tval,tamo,ans;
bool tmp;
struct node{
    int x,val,amo;
    bool operator <(node b)const{
        return b.val < val;
    }
}t;
struct ways{
    int tim,amo;
};
vector<node>E[2005];
priority_queue<node>pq;
vector<ways>all[2005];
int main(){
    int i,j;
    scanf("%d%d%d%d",&N,&s,&e,&M);
    for(i = 0;i < M;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        E[t1].push_back({t2,t3,0});
    }
    pq.push({s,0,0});
    while(!pq.empty())
    {
        t = pq.top(); pq.pop();
        if(t.x == e) continue;
        tamo = t.amo+1;
        for(i = 0;i < E[t.x].size();i++)
        {
            tx = E[t.x][i].x;
            tval = t.val+E[t.x][i].val;
            tmp = true;
            for(j = 0;j < all[tx].size();j++)
                if(all[tx][j].tim <= tval && all[tx][j].amo <= tamo)
                {
                    tmp = false;
                    break;
                }
            if(tmp)
            {
                all[tx].push_back({tval,tamo});
                pq.push({tx,tval,tamo});
            }
        }
    }
    scanf("%d",&Q);
    for(i = 0;i < Q;i++)
    {
        scanf("%d",&H);
        ans = 1e9;
        for(j = 0;j < all[e].size();j++) ans = min(ans,((all[e][j].amo-1)*H)+all[e][j].tim);
        printf("%d ",ans);
    }
}