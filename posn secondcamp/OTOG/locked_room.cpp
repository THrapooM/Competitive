#include<bits/stdc++.h>
using namespace std;
int N,i,j,arr[60][60],sx,sy,ex,ey,tx,ty;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int visited[60][60][2];
struct axis{
    int x,y,val;
    bool swit;
    bool operator < (axis k) const {
        return k.val < val;
    }
}t;
priority_queue<axis>heap;
bool border(int x,int y){
    if(x < 1 || y < 1 || x > N || y > N) return 0;
    return 1;
}
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= N ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    heap.push({sx,sy,0,0});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        if(visited[t.x][t.y][t.swit]) continue;
        visited[t.x][t.y][t.swit] = true;
        //printf("t.x = %d t.y = %d t.val = %d t.swit = %d\n",t.x,t.y,t.val,t.swit);
        if(t.x==ex&&t.y==ey&&t.swit==1) {printf("%d",t.val); return 0;}
        for(i = 0 ; i < 4 ; i++){
            tx = t.x + x[i];
            ty = t.y + y[i];
            if(border(tx,ty)){
            if(arr[tx][ty]<0) heap.push({tx,ty,t.val+abs(arr[tx][ty]),!t.swit});
            else heap.push({tx,ty,t.val+arr[tx][ty],t.swit});
            }
        }
    }
}