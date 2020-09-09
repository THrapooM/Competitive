#include<bits/stdc++.h>
using namespace std;
int N,_MAXTE,_MAXT,_LVLT,x,_NTBF,cnt,ans = -1;
vector<int>lvl[100005],from[100005];
bool ready[100005],visited[100005];
void dfs(int x){
    if(ready[x]) return;
    if(visited[x]){
        cnt = 1e9;
        return;
    }
    visited[x] = true;
    cnt++;
    for(int i = 0 ; i < from[x].size() ; i++){
        dfs(from[x][i]);
    }
    ready[x] = true;
    return;
}
int main(){
     scanf("%d%d%d",&N,&_MAXTE,&_MAXT);
     for(int i = 1 ; i <= N ; i++){
         scanf("%d%d",&_LVLT,&x);
         lvl[_LVLT].push_back(i);
         for(int j = 0 ; j < x; j++){
             scanf("%d",&_NTBF);
             from[i].push_back(_NTBF);
         }
     }
     for(int i = 1 ; i <= _MAXTE ; i++){
         memset(visited,0,sizeof(visited));
         for(int j = 0 ; j < lvl[i].size() ; j++)
            dfs(lvl[i][j]);
        if(cnt <= _MAXT) ans = i;
        else break;
     }
     printf("%d",ans);

}