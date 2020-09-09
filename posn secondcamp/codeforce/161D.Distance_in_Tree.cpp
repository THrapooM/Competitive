// #include<bits/stdc++.h>
// using namespace std;
// int i,N,K,t1,t2,cnt;
// vector<int>from[50005];
// bool visited[50005];
// void dfs(int x,int val){
//     if(visited[x]) return;
//     visited[x] = true;
//     if(val==K) {cnt++; return;}
//     for(int i = 0 ; i < from[x].size() ; i++)
//         dfs(from[x][i],val+1);
//     return;

// }
// int main(){
//     scanf("%d%d",&N,&K);
//     for(i = 0 ; i < N-1 ; i++){
//         scanf("%d%d",&t1,&t2);
//         from[t1].push_back(t2);
//         from[t2].push_back(t1);
//     }
//     for(i = 1 ; i <= N ; i++){
//         memset(visited,0,sizeof(visited));
//         dfs(i,0);
//     }
//     printf("%d",cnt/2);
// }
#include <bits/stdc++.h>
using namespace std;
int i,n,k,ans;
int t1,t2;
vector <int> v[50005];
int mem[50001][501];
void dfs(int u, int last){
    mem[u][0] = 1;
    for (auto g : v[u]){
        if (g == last) continue;
        dfs(g,u);
        for (int j = 1; j <= k; j++) ans += mem[u][j-1]*mem[g][k-j];
        for (int j = 1; j <= k; j++) mem[u][j] += mem[g][j-1];
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1,0);
    printf("%d",ans);
}
