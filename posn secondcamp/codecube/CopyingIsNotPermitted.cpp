#include<bits/stdc++.h>
using namespace std;
int V,E,Q,i,t1,t2,t3,tx,tval,u,v;
struct axis{
    int x,val,y;
}t,q[50005];
vector<axis>from[40005];
int check[40005];
bool visited[40005];
void dfs(int st,int val,int mark){
    visited[st] = true;
    check[st] = mark;
    for(int i=0;i<from[st].size();i++){
        tx = from[st][i].x;
        tval = from[st][i].val;
        if(val>tval && !visited[tx]) dfs(tx,val,mark);
    }
}
//if same head btw they can cheat
bool find(int val){
    memset(visited,0,sizeof(visited));
    bool found;
    for(int i=1;i<=V;i++)
        if(!visited[i])  dfs(i,val,i);
    for(int i = 0;i<Q;i++){
        if(check[q[i].x]==check[q[i].y]) return false;
    }
    return true;
}
int main(){
    scanf("%d%d%d",&V,&E,&Q);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        from[t1].push_back({t2,t3});
        from[t2].push_back({t1,t3});
    }
    for(i=0;i<Q;i++) scanf("%d%d",&q[i].x,&q[i].y);  
    int l = 1,r = 1e9,mid;
    while(l<=r){
        mid = (l + r) >> 1;
        u = find(mid),v = find(mid+1);
        //printf("mid = %d\n",mid); 
        if(u&&!v){
            printf("%d",mid);
            return 0;
        }
        else if(u&&v) l = mid+1;
        else r = mid-1;
    }
    if(mid==1e9) printf("-1");
}