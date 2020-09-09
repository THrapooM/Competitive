#include<bits/stdc++.h>
using namespace std;
int i,N,K,t1,t2,cnt;
vector<int>from[50005];
bool visited[50005];
void dfs(int x,int val){
    if(visited[x]) return;
    visited[x] = true;
    if(val==K) {cnt++; return;}
    for(int i = 0 ; i < from[x].size() ; i++)
        dfs(from[x][i],val+1);
    return;

}
int main(){
    scanf("%d%d",&N,&K);
    for(i = 0 ; i < N-1 ; i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
    }
    for(i = 1 ; i <= N ; i++){
        memset(visited,0,sizeof(visited));
        dfs(i,0);
    }
    printf("%d",cnt/2);
}