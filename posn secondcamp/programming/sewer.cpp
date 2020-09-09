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
    scanf("%d%d",&nx,&ny);
    int i,j;
    for(i=1; i<=nx; i++)
    {
        for(j=1; j<=ny; j++)
        {
            scanf(" %c",&c);
            if(c=='B')
                a[i][j][1] = a[i][j][3] =a[i][j+1][2] = a[i+1][j][0] =  1;
            else if(c=='R')
                a[i][j][3] = a[i][j+1][2]= 1;
            else if(c=='D')
                a[i][j][1]=a[i+1][j][0]= 1;
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
                printf("%d %d\n",tx,ty);
//                for(i=1;i<=nx;i++){
//        for(j=1;j<=ny;j++){
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

