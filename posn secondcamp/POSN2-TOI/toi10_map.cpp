#include<bits/stdc++.h>
using namespace std;
int N,M,i,t1,t3,tx,ty,tval,minx = 1e9,miny = 1e9,j;
struct axis{
    int x,y,val;
}t;
char t2;
queue<axis>que;
vector<axis>v[40005];
int mem[410][410];
int main(){
    memset(mem,-1,sizeof(mem));
    scanf("%d%d",&N,&M);
    for(i = 0 ; i < N*M -1 ; i++){
        scanf("%d %c%d",&t1,&t2,&t3);
       if(t2=='U') v[t1].push_back({1,0,t3}),v[t3].push_back({-1,0,t1});
        else v[t1].push_back({0,1,t3}),v[t3].push_back({0,-1,t1});
    }
    que.push({205,205,t1});
    while(!que.empty()){
        t = que.front(); que.pop();
        if(mem[t.x][t.y]!=-1) continue;
        mem[t.x][t.y] = t.val;
        minx = min(t.x,minx);
        miny = min(t.y,miny);                                        
        for(i = 0 ; i < v[t.val].size() ; i++){
            tx = v[t.val][i].x + t.x;
            ty = v[t.val][i].y + t.y;
            tval =v[t.val][i].val;
            que.push({tx,ty,tval});
        }
    }
    for(i = minx ; i < minx+N ; i++){
        for(j = miny ; j < miny+M ; j++){
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
}