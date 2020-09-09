#include<bits/stdc++.h>
using namespace std;
int N,M,T,i,order,temp,j,t1,cnt,ans;
vector<int>from[100005],lvl[10005];
bool visited[100005],mark[100005];
void dfs(int now){
    if(!mark[now]){
    if(visited[now]){
        cnt = 1e9;
        return;
    }
    visited[now] = true;
    cnt++;
    for(int i = 0 ; i < from[now].size() ; i++)
        dfs(from[now][i]);
    mark[now] = true;
    }
    return;
}
int main(){
    scanf("%d%d%d",&N,&M,&T);
    for(i = 1 ; i <= N ; i++){
        scanf("%d%d",&order,&temp);
        lvl[order].push_back(i);
        if(!temp) cnt++,mark[i] = true;
        for(j = 0 ; j < temp ; j++){
            scanf("%d",&t1);
            from[i].push_back(t1);
        }
    }
    for(i = 1 ; i <= M ; i++){
        memset(visited,0,sizeof(visited));
        for(j = 0 ; j < lvl[i].size(); j++) dfs(lvl[i][j]);
        if(cnt <= T) ans = i;
        else break;
    }
    if(!ans) ans = -1;
    printf("%d",ans);
}