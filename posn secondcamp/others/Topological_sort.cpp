#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
stack<int>st;
vector<int>from[1005];
void dfs(int x){
    visited[x] = true;
    for(int j=0;j<from[x].size();j++){
        if(visited[from[x][j]]) continue;
        dfs(from[x][j]);
    }
    st.push(x);
}
int main(){
    int i,V,E,t1,t2;
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
    }
    for(i=1;i<=V;i++){
        if(visited[i]) continue;
        dfs(i);
    }
    while(!st.empty()){
        printf("%d ",st.top()); st.pop();
    }
}