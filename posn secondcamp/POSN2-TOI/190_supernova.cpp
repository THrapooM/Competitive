#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int N,M,t1,t2,i,deg[MAXN],U[MAXN],V[MAXN],j,t,siz[MAXN],ans[MAXN];
queue<int>que;
struct axis{
    int x,di;
};
vector<axis>from[MAXN];
bool visited[MAXN];
void dfs(int now,int par,int edge){
        siz[now] = 1;
        for(int i = 0 ; i < from[now].size() ; i++){
            if(!deg[from[now][i].x] && from[now][i].x!=par){
                dfs(from[now][i].x,now,from[now][i].di);
                siz[now] += siz[from[now][i].x];
            }
        }
    ans[edge] = siz[now] * (N-siz[now]);
}
int main(){
    scanf("%d%d",&N,&M);
    for(i = 1 ; i <= N ; i++){
        scanf("%d%d",&t1,&t2);
        U[i] = t1,V[i] = t2;
        from[t1].push_back({t2,i});
        from[t2].push_back({t1,i});
        ++deg[t1],++deg[t2];
    }
    for(i = 1 ; i <= N ; i++){
        if(deg[i]==1 && !visited[i]) que.push(i);
        while(!que.empty()){
            t = que.front(); que.pop();
            visited[t] = true;
            for(j = 0 ; j < from[t].size() ; j++){
                if(deg[from[t][j].x]){
                    --deg[t];
                    if(--deg[from[t][j].x]==1) que.push(from[t][j].x);
                }
            }
        }
    }
    for(i = 1 ; i <= N ; i++) if(deg[i]==2) dfs(i,0,0);
    //for(i = 1 ; i <= N ; i++) printf("sz[%d] = %d\n",i,siz[i]);
    for(i = 1 ; i <= N ; i++){
        if(deg[U[i]]==2 && deg[V[i]]==2) printf("0 ");
        else printf("%d ",ans[i]);
    }
}