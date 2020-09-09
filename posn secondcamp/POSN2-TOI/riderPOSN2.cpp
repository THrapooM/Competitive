#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,move;
}t;
queue<axis>q;
//KU
int x[] = {0,0,-1,1,-1,1};
int y[] = {-1,1,0,0,1,1};
//kii
int xx[] = {0,0,-1,1,-1,1};
int yy[] = {-1,1,0,0,-1,-1};
int i,j,n,m,a[105][105],X,Y;
int mem[105][105][5005];
bool check(int x,int y){
    if(x<0 || y<0 || x>m-1||y>n-1) return 0;
    return 1;
}
int main(){
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(a[(m-1)/2-1][0]!=0) q.push({(m-1)/2-1,0,1});
    if(a[(m-1)/2][0]!=0) q.push({(m-1)/2,0,1});
    if(a[(m-1)/2+1][0]!=0) q.push({(m-1)/2+1,0,1});
    while(!q.empty()){
        t = q.front(); q.pop();
      //  printf("a[%d][%d] =  %d :: mem[%d][%d][%d] = %d\n",t.x,t.y,a[t.x][t.y],t.x,t.y,t.move,mem[t.x][t.y][t.move]);
        if(t.x==(m-1)/2&&t.y==n-1){
            printf("%d",t.move);
            return 0;
        }
        for(i=0;i<6;i++){
            if(t.x%2==0){
                X = t.x + x[i];
                Y = t.y + y[i];
                if(a[X][Y]!=0&&!mem[X][Y][t.move+1]&&(t.move+1)%a[X][Y]==0&&check(X,Y)){
               // printf("move = %d,a[%d][%d]= %d,t.x=%d\n",t.move,X,Y,a[X][Y],t.x);
                    mem[X][Y][t.move+1] = mem[t.x][t.y][t.move]+1;
                    q.push({X,Y,t.move+1});
                }
            }
            else if(t.x%2==1){
                 X = t.x + xx[i];
                 Y = t.y + yy[i];
                if(a[X][Y]!=0&&!mem[X][Y][t.move+1]&&(t.move+1)%a[X][Y]==0&&check(X,Y)){
                 //printf("move = %d,a[%d][%d]= %d,t.x=%d\n",t.move,X,Y,a[X][Y],t.x);
                    mem[X][Y][t.move+1] = mem[t.x][t.y][t.move]+1;
                    q.push({X,Y,t.move+1});
            }
        }
    }
    }

}