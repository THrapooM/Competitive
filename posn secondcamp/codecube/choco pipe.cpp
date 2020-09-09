#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,val,di;
    bool operator < (axis k) const{
        return k.val < val;
    }
}t;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int cost[3],n,m,mem[105][105][4],a[105][105],tval,i,j;
char c;
bool check(int X,int Y){
    if(X >=1 && X <= m && Y >=1 && Y <=n) return 1;
    if(X==m && Y==n+1) return 1;
    return 0;
}
priority_queue<axis>heap;
int main(){
    fill(&mem[0][0][0],&mem[104][104][3],1e9);
    scanf("%d%d%d",&cost[0],&cost[1],&cost[2]);
    scanf("%d%d",&n,&m);
    for(i=m;i>=1;i--){
        for(j=1;j<=n;j++){
            scanf(" %c",&c);
            if(c=='X') a[i][j] = cost[2];
        }
    }
    mem[1][0][1] = 0;
    heap.push({1,0,0,1});
    while(!heap.empty()){
        t  = heap.top(); heap.pop();
        if(t.x==m&&t.y==n+1) {printf("%d",mem[t.x][t.y][t.di]-cost[0]); return 0;}
        for(i=0;i<4;i++){
            if(i==2) continue;
            int gt = (i+t.di)%4;
            int X = t.x+x[gt];
            int Y = t.y+y[gt];
            if(gt!=t.di) tval = t.val + a[X][Y] + cost[1];
            else tval = t.val + a[X][Y] + cost[0];
            if(check(X,Y) && tval < mem[X][Y][gt]){
                mem[X][Y][gt] = tval;
                heap.push({X,Y,tval,gt});
            }
        }
    }
}