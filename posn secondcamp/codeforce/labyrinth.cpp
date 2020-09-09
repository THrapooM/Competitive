#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,l,r;
}t;
int N,M,sx,sy,l,r,i,j,cnt;
char mapp[2005][2005];
deque<axis>deq;
int main(){
    scanf("%d%d%d%d%d%d",&N,&M,&sx,&sy,&l,&r);
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= M ; j++){
            scanf(" %c",&mapp[i][j]);
        }
    }
    deq.push_front({sx,sy,l,r});
    while(!deq.empty()){
        t = deq.front(); deq.pop_front();
        if(mapp[t.x][t.y]=='*') continue;
        mapp[t.x][t.y] = '*';
        cnt++;
        if(t.x>1&&mapp[t.x-1][t.y]=='.') deq.push_front({t.x-1,t.y,t.l,t.r});
        if(t.x<N&&mapp[t.x+1][t.y]=='.') deq.push_front({t.x+1,t.y,t.l,t.r});
        if(t.y>1&&mapp[t.x][t.y-1]=='.'&&t.l) deq.push_back({t.x,t.y-1,t.l-1,t.r});
        if(t.y<M&&mapp[t.x][t.y+1]=='.'&&t.r) deq.push_back({t.x,t.y+1,t.l,t.r-1});
    }
    printf("%d",cnt);
}