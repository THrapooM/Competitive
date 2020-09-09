#include<bits/stdc++.h>
using namespace std;
int N,V,E,weakp,t1,t2,h[500005],St;
vector<int>from[500005];
bool visited[500005];
int mem[500005];
int _MAX = -1,ans;
bool dfs(int x){
    h[x] = St;
    bool che = true,tmp;
    visited[x] = true;
    for(int i = 0 ; i < from[x].size() ; i++){
            if(!visited[from[x][i]]){
                tmp = dfs(from[x][i]);
                if(tmp) mem[x] += mem[from[x][i]]+1;
                che &= tmp;
            }
            else if(h[x]!=h[from[x][i]]){
                che = false;
            }
    }
    return che;
}
int main(){
    scanf("%d%d",&E,&weakp);
    visited[weakp] = true;
    for(int i = 1 ; i <= E ; i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
    }
    for(int i = 0 ; i <from[weakp].size() ; i++){
        h[from[weakp][i]] = from[weakp][i];
        visited[from[weakp][i]] = true;
    }
    for(int i = 0 ; i < from[weakp].size() ; i++){
        St = from[weakp][i];
        h[weakp] = St;
        dfs(St);
    }

  //  for(int i = 1 ; i <= E ; i++) printf("mem[%d] = %d\n",i,mem[i]);
    for(int i = 1 ; i <= E ; i++){
        if(i==weakp) continue;
        if(_MAX < mem[i]) _MAX = mem[i],ans = i;
    }
    //printf("\n");
    //for(int i = 1 ; i <= E ; i++) printf("mem[%d] = %d",i,mem[i]);
    printf("%d\n%d",ans,_MAX);
}