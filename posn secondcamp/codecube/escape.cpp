#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y;
};
int x[] = {1,0};
int y[] = {0,1};
int i,j,n,m;
int a[1005][1005];
int mem[1005][1005];
queue<axis>q;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j] = !a[i][j];
        }
    }
    q.push({1,1});
    mem[1][1] = 1;
    while(!q.empty()){

        axis t = q.front(); q.pop();
        for(i=0;i<2;i++){
            int X = t.x +x[i];
            int Y = t.y+ y[i];
            if(a[X][Y]){
                if(!mem[X][Y]) q.push({X,Y});
                mem[X][Y] += mem[t.x][t.y]%1000000007;
            }
        }
    }
    printf("%d",mem[n][m]);
}
