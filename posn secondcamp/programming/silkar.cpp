#include<bits/stdc++.h>
using namespace std;
struct axis
{
    int x,y;
};
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int sx,sy,fx,fy,nx,ny;
int i,j,z;
queue<axis>q;
queue<axis>go;
bool check(int x,int y)
{
    if(x<1 || y<1 || x>nx || y>ny)
        return 0;
    return 1;
}
int w[55][55],went[55][55],floatt[55][55],mem[55][55],mem1[55][55];
char a[55][55];
int main()
{
    scanf("%d%d",&nx,&ny);
    for(i=1; i<=nx; i++)
    {
        for(j=1; j<=ny; j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='.')
                w[i][j]=1;
            else if(a[i][j]=='S')
                go.push({i,j});
                else if(a[i][j]=='*')
                q.push({i,j});
                else if(a[i][j]=='X')
                w[i][j]=0;
                else if(a[i][j]=='D')
                {
                    fx = i; fy = j;
                    w[i][j]=1;
                }
        }
    }
    while(1)
    {
        while(!q.empty())
        {
            axis t = q.front(); q.pop();
            for(i=0; i<4; i++)
            {   int X = t.x+x[i];
                int Y = t.y+y[i];
                if(check(X,Y)&&w[X][Y]&&!went[X][Y])
                {
                    if(X==fx&&Y==fy) continue;
                    floatt[X][Y] = 1;
                }
            }
        }
        while(!go.empty())
        {
            axis n = go.front(); go.pop();
            for(j=0; j<4; j++)
            {
                int X = n.x+x[j];
                int Y = n.y+y[j];
                if(check(X,Y)&&w[X][Y]&&!floatt[X][Y]&&!went[X][Y]){
                    went[X][Y] = went[n.x][n.y]+1;
            }
            }
        }
        for(i=1;i<=nx;i++){
            for(j=1;j<=ny;j++){
                if(floatt[i][j]&&mem[i][j]==0) {mem[i][j]=1;q.push({i,j});}
                else if(went[i][j]&&mem1[i][j]==0){mem1[i][j]=1; go.push({i,j});}
            }
        }
        if(((q.empty())&&go.empty()))break;
    }
//    for(i=1;i<=nx;i++){
//        for(j=1;j<=ny;j++){
//            printf("%d ",went[i][j]);
//        }
//        printf("\n");
//    }
       if(went[fx][fy]) printf("%d",went[fx][fy]);
       else printf("KAKTUS");
}
