#include<bits/stdc++.h>
using namespace std;
struct axis
{
    int x,y,j,b,p;
};
int n,m;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int X,Y;
int mem[505][505][2][2][2];
int coor[505][505];
int lx,ly;
int j,b,p;
bool check(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    return 1;
}
queue <axis> q;
int main()
{

    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf(" %c",&coor[i][j]);
            if(coor[i][j]=='S')
                q.push({i,j,0,0,0});
            else if(coor[i][j]=='E')
            {
                lx = i;
                ly = j;
            }
        }
    }
    while(!q.empty())
    {
        axis t = q.front();
        q.pop();
        if(t.x==lx&&t.y==ly)
        {
            printf("%d",mem[lx][ly][t.j][t.b][t.p]);
            return 0;
        }
        for(i=0; i<4; i++)
        {
            X = t.x +x[i];
            Y = t.y+y[i];
            if(check(X,Y)&&!mem[X][Y][t.j][t.b][t.p]&&coor[X][Y]!='#')
            {
                if(coor[X][Y]=='.'||coor[X][Y]=='E'||coor[X][Y]=='S'||coor[X][Y]=='J'&&t.j||coor[X][Y]=='B'&&t.b||coor[X][Y]=='P'&&t.p)
                {
                    mem[X][Y][t.j][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p]+1;
                    q.push({X,Y,t.j,t.b,t.p});
                }
                if(coor[X][Y]=='j'||coor[X][Y]=='b'||coor[X][Y]=='p')
                {
                    if (coor[X][Y]=='j' && !t.j)
                    {
                        mem[X][Y][1][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,1,t.b,t.p});
                    }
                    else if(coor[X][Y]=='b' && !t.b)
                    {
                        mem[X][Y][t.j][1][t.p] = mem[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,t.j,1,t.p});
                    }
                    else if(coor[X][Y]=='p' && !t.p)
                    {
                        mem[X][Y][t.j][t.b][1] = mem[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,t.j,t.b,1});
                    }
                    else
                    {
                        mem[X][Y][t.j][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,t.j,t.b,t.p});
                    }
                }
            }
//        printf("mem[%d][%d][%d][%d][%d] = %d\n",t.x,t.y,t.j,t.b,t.p,mem[t.x][t.y][t.j][t.b][t.p]);
        }
    }
    cout<<-1;

}
