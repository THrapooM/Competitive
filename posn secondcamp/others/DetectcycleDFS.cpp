// #include<bits/stdc++.h>
// using namespace std;
// int color[10005],V,E,t1,t2,i;
// vector<int>from[10005];
// bool dfs(int u){
//         if(color[u]==1) return 1;
//         if(color[u]==2) return 0;
//         color[u] = 1;
//         for(int i = 0 ; i < from[u].size() ; i++){
//             if(dfs(from[u][i])) return 1;
//         }
//         color[u] = 2;
// }
// int main(){
//     scanf("%d%d",&V,&E);
//     for(i = 1 ; i <= E ; i++){
//         scanf("%d%d",&t1,&t2);
//         from[t1].push_back(t2);
//     }
//     for(i = 1 ; i <= V ; i++){
//         if(dfs(i)){
//                 printf("found cycle");
//         }
//     }
// }   
#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2,vis[10005];
vector<int>from[10005];
bool dfs(int u,int p){
    if(vis[u]) return 1;
    vis[u] = true;
    for(int i = 0 ; i < from[u].size() ; i++){
        if(from[u][i]==p) continue;
        if(dfs(from[u][i],u)) return 1;
    }
    return false;
}
int main(){
        scanf("%d%d",&V,&E);
        for(i = 1 ; i <= E ; i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
    }
    for(i = 1 ; i <= V ; i++){
        if(!vis[i]){
            if(dfs(i,0)){
                printf("found cycle");

            }
        }
    }

}