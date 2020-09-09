#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int nx,ny;
char c;
queue<node>q;
bool a[105][105][4];
int go[105][105];
int main()
{
    scanf("%d%d",&ny,&nx);
    int i,j;
    for(i=1; i<=ny; i++)
    {
        for(j=1; j<=nx; j++)
        {
            scanf(" %c",&c);
            if(c=='B')
                a[j][i][1] = a[j][i][3] = a[j][i+1][2] = a[j+1][i][0] = 1;
            else if(c=='R')
                a[j][i][1] = a[j+1][i][0] = 1;
            else if(c=='D')
                a[j][i][3] = a[j][i+1][2] = 1;
//        else if(c=='N') a[i][j][1] = a[i][j][2] = a[i][j]
            //else if(c=='N')
        }
    }
    go[1][1]=1;
    int tx,ty;
    q.push({1,1});
    while(!q.empty())
    {
        node t = q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            tx = t.x+x[i];
            ty = t.y+y[i];
            if(a[t.x][t.y][i]&&!go[tx][ty])
            {
                go[tx][ty] = go[t.x][t.y]+1 ;
                q.push({tx,ty});
            }
            else if(a[t.x][t.y][i] && go[tx][ty])
            {
                if(go[t.x][t.y]+1==go[tx][ty]){
                printf("%d\n",go[tx][ty]);
                printf("%d %d\n",ty,tx);
//                for(i=1;i<=ny;i++){
//        for(j=1;j<=nx;j++){
//            printf("%d ",go[i][j]);
//        }
//        printf("\n");
//    }
                return 0;
            }
        }
    }

//    for(i=1;i<=nx;i++){
//        for(j=1;j<=ny;j++){
//            printf("%d ",go[i][j]);
//        }
//        printf("\n");
//    }
}
}

