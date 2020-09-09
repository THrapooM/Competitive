#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,cnt,tx,ty,tdi;
int mem[305][305],sew[305][305],used[305][305];
struct axis{
    int x,y,dir;
}t;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
queue<axis>que,nque;
void nahee(int st){
    nque.push({tx,ty,tdi});
    while(!nque.empty()){
        t = nque.front(); nque.pop();
        tx = t.x + x[t.dir];
        ty = t.y + y[t.dir];
        if(!mem[tx][ty]){
            mem[tx][ty] = mem[t.x][t.y]+1;
            if(sew[tx][ty]==11 && t.di==)
            else if(sew[tx][ty]==12)
            else if(sew[tx][ty]==13)
            else if(sew[tx][ty]==14)
            else if(sew[tx][ty]==21)
            else if(sew[tx][ty]==22)
            else if(sew[tx][ty]==31)
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= M ; j++){
            scanf("%d",&sew[i][j]);
            if(i==1){
                if(sew[i][j]==11 || sew[i][j]==12 || sew[i][j]==21 || sew[i][j]==31) cnt++,que.push({i-1,j,1}),used[i-1][j] = true;
            }
            if(j==1){
                if(sew[i][j]==13 || sew[i][j]==11 || sew[i][j]==22 || sew[i][j]==31) cnt++,que.push({i,j-1,3}),used[i][j-1] = true;
            }
            if(i==N){
                if(sew[i][j]==13 || sew[i][j]==14 || sew[i][j]==21 || sew[i][j]==31) cnt++,que.push({i+1,j,0}),used[i+1][j] = true;
            }
            if(j==M){
                if(sew[i][j]==12 || sew[i][j]==14 || sew[i][j]==22 || sew[i][j]==31) cnt++,que.push({i,j+1,2}),used[i][j+1] = true;
            }
        }
    }
    while(!que.empty()){
        t = que.front(); que.pop();
        tx = t.x,ty = t.y,tdi = t.dir;
        nahee(1);
    }


}