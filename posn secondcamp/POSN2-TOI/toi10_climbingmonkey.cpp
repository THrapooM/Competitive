#include<bits/stdc++.h>
using namespace std;
int H,N,T,st,t1,t2,i;
struct axis{
    int x,height,used;
}t;
vector<axis>from[200005];
int hei[200005];
queue<axis>que;
int main(){
    scanf("%d%d%d",&H,&N,&T);
    for(i =1 ; i <= N ; i++) scanf("%d",&hei[i]);
    for(i =1 ; i <= T ; i++){
        scanf("%d%d",&t1,&t2);
            from[t1].push_back({t1+1,t2,0});
            from[t1+1].push_back({t1,t2,0});
    }
    scanf("%d",&st);
    que.push({st,0,0});
    while(!que.empty()){
        t = que.front(); que.pop();
        
    }
    
}