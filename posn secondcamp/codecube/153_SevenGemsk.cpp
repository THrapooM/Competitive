#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,sx,sy,nt,tx,ty,ex,ey;    
char path[205][205];
int a[205][205];
// map<int,map<int,map<int,bool>>>visited;
int mem[202][202][8][130];
struct axis{
    int x,y,tim,vis,cg;
}t;
int x[] = {0,-1,1,0,0};
int y[] = {0,0,0,1,-1};
queue<axis>que;
bool border(int x,int y){
    if(x < 1 || y < 1 || x > N || y > M) return 0;
    return 1;
}
void check(){
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= M ; j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int tmp,cnt = 0;
    scanf("%d%d",&N,&M);
    for(i = 1 ; i <= N ; i++){
        for(j =1 ; j <= M ; j++){
            scanf(" %c",&path[i][j]);
            if(path[i][j]=='S') sx = i,sy =j;
            else if(path[i][j]-'0' >= 1 && path[i][j]-'0' <= 6) a[i][j] = path[i][j]-'0';
            else if(path[i][j]=='G') a[i][j]=cnt,cnt++;
            else if(path[i][j]=='#') a[i][j] = 0;
        }
    }
    // check();
    que.push({sx,sy,1,0,0});
    while(!que.empty()){
        t = que.front(); que.pop();
       // printf("mem[%d][%d][%d][%d] = %d\n",t.x,t.y,t.tim,t.vis,mem[t.x][t.y][t.tim][t.vis]);
        if(t.vis==(1<<7)-1) {printf("%d",mem[t.x][t.y][t.tim][t.vis]); return 0;}
        nt = (t.tim%6)+1;
        for(i = 0 ; i < 5 ; i++){
            tx = t.x + x[i];
            ty = t.y + y[i];
            if(border(tx,ty) && path[tx][ty]!='#'){
                if(path[tx][ty]=='G' && !mem[tx][ty][nt][t.vis|(1<<(a[tx][ty]))] || mem[tx][ty][nt][]){
                    mem[tx][ty][nt][t.vis|(1<<(a[tx][ty]))] = mem[t.x][t.y][t.tim][t.vis]+1;
                    que.push({tx,ty,nt,t.vis|(1<<(a[tx][ty])),t.cg+1});
                }
                 else if((a[tx][ty] >=1 && a[tx][ty] <=6) && !mem[tx][ty][nt][t.vis]){
                    if(i==0 && nt!=a[tx][ty]) continue;
                    if((nt==a[tx][ty]) || (t.cg>=a[tx][ty])){
                    mem[tx][ty][nt][t.vis] = mem[t.x][t.y][t.tim][t.vis]+1;
                    que.push({tx,ty,nt,t.vis,t.cg});
                    }
                }
                else if((path[tx][ty]=='S' || path[tx][ty]=='.') && !mem[tx][ty][nt][t.vis]){
                    mem[tx][ty][nt][t.vis] = mem[t.x][t.y][t.tim][t.vis]+1;
                    que.push({tx,ty,nt,t.vis,t.cg});
                }
            }
        }
    }
    printf("-1");
}