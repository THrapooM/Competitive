#include<bits/stdc++.h>
using namespace std;
int i,n,m,j;
bool a[2005][2005],val[2005][2005];
struct axis{
    int x,y;
}t;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
queue<axis>q;
char t1;
int k,cnt,ans;
int mem[2005][2005];
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&t1);
            if(t1=='W') a[i][j] = 0;
            else if(t1=='A') {val[i][j] = 1; a[i][j] = 1;}
            else if(t1=='X') {a[i][j]=0;q.push({i,j});}
            else a[i][j] = 1;
        }
    }
    while(!q.empty()){
        t = q.front(); q.pop();
       // printf("mem[%d][%d][%d] = mem[%d]\n",t.x,t.y,t.bot,mem[t.x][t.y][t.bot]);
        for(i=0;i<4;i++){
            int X = t.x+x[i];
            int Y = t.y+y[i];
            if(a[X][Y]&&!mem[X][Y]){
                mem[X][Y] = mem[t.x][t.y]+1;
                if(val[X][Y]){
                    cnt++;
                    val[X][Y] = 0;
                    ans += mem[X][Y];
                }
                q.push({X,Y});
            }
        }
    }
    printf("%d %d",cnt,ans*2);
}