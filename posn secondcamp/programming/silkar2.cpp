#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y;
};
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
queue<axis>q;
queue<axis>wa;
int a[55][55];
int memw[55][55],memp[55][55];
int r,c,ey,ex,i,j;
char s;
bool check(int x,int y){
    if(x <= r && x>=1 && y<=c && y>=1) return 1;
    return 0;
}
int main(){
    memset(a,1,sizeof(a));
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf(" %c",&s);
            if(s=='S') {q.push({i,j}); memp[i][j]=1;}
            else if(s=='D') {ey = i,ex = j,a[i][j]=0;}
            else if(s=='*') {wa.push({i,j});memw[i][j]=1;}
            else if(s=='X') a[i][j] = 0;

        }
    }
    while(!wa.empty()){
        axis t = wa.front(); wa.pop();
        for(i=0;i<4;i++){
            int X = t.x+x[i];
            int Y = t.y+y[i];
            if(check(X,Y)&&a[X][Y]&&!memw[X][Y]){
                memw[X][Y] = memw[t.x][t.y]+1;
                wa.push({X,Y});
            }
        }
    }
    while(!q.empty()){
        axis t = q.front(); q.pop();
        for(i=0;i<4;i++){
            int X = t.x+x[i];
            int Y = t.y+y[i];
            if(X==ey&&Y==ex) {printf("%d",memp[t.x][t.y]); return 0;}
            if(check(X,Y)&&a[X][Y]&&!memp[X][Y]){
                memp[X][Y] = memp[t.x][t.y]+1;
                if(memp[X][Y]<memw[X][Y] || !memw[X][Y]) q.push({X,Y});
            }
        }
    }
    printf("KAKTUS");
}
