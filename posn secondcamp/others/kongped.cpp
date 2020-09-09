#include <bits/stdc++.h>
using namespace std;
int n,m,mem[505][505][20],a[505][505][2],ex,ey,nx,ny,nval;
int cx[]={-1,0,1,0};
int cy[]={0,1,0,-1};
struct node{
    int x,y,val,amo;
}t;
queue<node>q;
char c;
bool bor(int x,int y){
    if(x>=0 && y>=0 && x<n && y<m) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %c",&c);
            if(c=='.') a[i][j][1]=1,a[i][j][0]=1;
            else if(c=='D') a[i][j][1]=2,a[i][j][0]=0;
            else if(c=='B') a[i][j][1]=4,a[i][j][0]=0;
            else if(c=='J') a[i][j][1]=8,a[i][j][0]=0;
            else if(c=='d') a[i][j][1]=2,a[i][j][0]=1;
            else if(c=='b') a[i][j][1]=4,a[i][j][0]=1;
            else if(c=='j') a[i][j][1]=8,a[i][j][0]=1;
            else if(c=='S') q.push({i,j,1,0}),a[i][j][1]=1;
            else if(c=='E') ex=i,ey=j,a[i][j][1]=1,a[i][j][0]=1;
        }
    }
    while(!q.empty())
    {
        t=q.front();
        q.pop();
//        printf("\nat %d %d val %d amo %d",t.x,t.y,t.val,t.amo);
        if(t.x==ex && t.y==ey)
        {
            printf("%d",t.amo);
            return 0;
        }
        for(i=0;i<4;i++)
        {
            nx=t.x+cx[i];
            ny=t.y+cy[i];
//            printf("\ngo to %d %d val %d(%d)(%d)",nx,ny,t.val,a[nx][ny][0],a[nx][ny][1]);
            if(a[nx][ny][0] && bor(nx,ny))
            {
                nval=t.val|a[nx][ny][1];
                if(!mem[nx][ny][nval] || t.amo+1<mem[nx][ny][nval])
                {
                    mem[nx][ny][nval]=t.amo+1;
                    q.push({nx,ny,nval,t.amo+1});
                }
            }else if(a[nx][ny][1]&t.val && bor(nx,ny))
            {
                if(!mem[nx][ny][t.val] || t.amo<mem[nx][ny][t.val])
                {
                    mem[nx][ny][t.val]=t.amo+1;
                    q.push({nx,ny,t.val,t.amo+1});
                }
            }
        }
    }
    printf("-1");
}
