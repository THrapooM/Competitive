#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,z;
};
queue <axis> q;
int n;
int x[] = {-1,0,1,0};
int y[] = {0,-1,0,1};
int m[1005][1005][4],X,Y,Z;
int w[1005][1005];
bool check(int x,int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return 0;
    return 1;
}
int main()
{
//   freopen("k.txt","r",stdin);
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&w[i][j]);
        }
    }
    q.push({0,0,2});
    q.push({0,0,3});
    while(!q.empty()){

        axis t = q.front(); q.pop();
        if(t.x==n-1&&t.y==n-1) {printf("%d",m[t.x][t.y][t.z]);return 0;}
            X = t.x+x[t.z]; Y = t.y+y[t.z];
            if(check(X,Y) && !m[X][Y][t.z] && !w[X][Y])
            {
             q.push({X,Y,t.z});
             m[X][Y][t.z] = m[t.x][t.y][t.z]+1;
            }
            else {
                for(i=0;i<4;i++){
                     X = t.x+x[i]; Y = t.y+y[i];
                     if(check(X,Y) && !m[X][Y][i] && !w[X][Y]){
                        q.push({X,Y,i});
                        m[X][Y][i] = m[t.x][t.y][t.z]+1;
                     }
                }
            }
//            printf("m[%d][%d][%d] = %d\n",t.x,t.y,t.z, m[t.x][t.y][t.z]);
        }
}
