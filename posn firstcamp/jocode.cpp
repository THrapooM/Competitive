#include <bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,z;
};
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int m[1005][1005],i,X,Y,Z;
int g[1005][1005];
int sx,sy,sz;
int j;
int n;
queue <axis> q;
bool check(int x, int y){
    if (x < 0 || y < 0 || x > n || y > n) return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
        scanf("%d",&g[i][j]);
        }
        q.push({sx,sy,sz});
        q.push({sx,sy,1});

     while (!q.empty()){
        axis t = q.front(); q.pop();
        if (check(X,Y) && !m[X][Y] && !g[X][Y]){
            q.push({X,Y,Z});
        }
        else for(i = 0; i < 4; i++){
                X = t.x+x[i], Y = t.y+y[i];
         if (check(X,Y) && !m[X][Y] && !g[X][Y]){
             if (X == sx && Y == sy ) continue;
                m[X][Y] = m[t.x][t.y]+1;
                q.push({X,Y,Z});
         }
    }
     }
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                printf("%d ",m[a][b]);
            }cout <<endl;
        }
}



