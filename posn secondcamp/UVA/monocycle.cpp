//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=988
#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[30][30];
int prev,ex,ey;
bool mem[30][30],k;
int mem1[30][30][5][4],cnt;
bool check(int fx,int fy)
{
    if(fx>=0 && fx<n && fy>=0 && fy<m)
        return 1;
    else
        return 0;
}
struct axis
{
    int x,y,col,f;
}t;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
queue<axis>q;
int i,j;
int main()
{
//     freopen("i10047.txt","r",stdin);
//         freopen("o10047.txt","w",stdout);
    while(cin >> n >> m)
    {
        k = false;
        if (cnt && m && n)printf("\n");
        if(n==0&&m==0)
            return 0;
        printf("Case #%d\n",++cnt);
        memset(mem,1,sizeof(mem));
        memset(mem1,0,sizeof(mem1));
        while(!q.empty()) q.pop();
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='S')
                    q.push({i,j,0,0});
                if(a[i][j]=='T')
                {
                    ex = i,ey=j;
                }
                if(a[i][j]=='#')
                    mem[i][j]=0;
            }
        }
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            //printf("mem1[%d][%d][%d][%d] = %d\n",t.x,t.y,t.col,t.f,mem1[t.x][t.y][t.col][t.f]);
            if(t.x==ex&&t.y==ey&&t.col==0)
            {
                printf("minimum time = %d sec\n",mem1[t.x][t.y][t.col][t.f]);
                k = true;
                break;
            }
            int X = t.x+x[t.f];
            int Y = t.y+y[t.f];
            if(mem[X][Y]&&check(X,Y))
            {
                if(!mem1[X][Y][(t.col+1)%5][t.f])
                {
                    mem1[X][Y][(t.col+1)%5][t.f] = mem1[t.x][t.y][t.col][t.f]+1;
                    q.push({X,Y,(t.col+1)%5,t.f});
                }
            }
            if(!mem1[t.x][t.y][t.col][(t.f+1)%4])
            {
                mem1[t.x][t.y][t.col][(t.f+1)%4] = mem1[t.x][t.y][t.col][t.f]+1;
                q.push({t.x,t.y,t.col,(t.f+1)%4});
            }
            if(!mem1[t.x][t.y][t.col][(t.f+3)%4])
            {
                mem1[t.x][t.y][t.col][(t.f+3)%4] = mem1[t.x][t.y][t.col][t.f]+1;
                q.push({t.x,t.y,t.col,(t.f+3)%4});
            }
        }
        if(!k)
            printf("destination not reachable\n");
    }
}
