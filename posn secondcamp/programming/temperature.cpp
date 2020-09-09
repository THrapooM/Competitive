//https://programming.in.th/task/rev2_problem.php?pid=1061
#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y;
};
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
queue <axis>q;
int a[21][21];
bool mem[25][25];
    int n,maxx=0;
//bool check(int a,int b){
//    if(a<1||a>n||b<1||b>n) return 0;
//    return 1;
//}
int main(){
    scanf("%d",&n);
    int i,j,sx,sy;
    scanf("%d%d",&sx,&sy);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    q.push({sy,sx});
    while(!q.empty()){
        axis t = q.front(); q.pop();
        for(i=0;i<4;i++){
            int X = t.x+x[i];
            int Y = t.y+y[i];
            if(a[X][Y]!=100&&a[X][Y]>a[t.x][t.y]&&!mem[X][Y]){
                    mem[X][Y] = true;
                    q.push({X,Y});
                    maxx = max(maxx,a[X][Y]);

            }
        }
    }
    if(n==1) {printf("%d",a[1][1]); return 0;}
    printf("%d",maxx);
}
