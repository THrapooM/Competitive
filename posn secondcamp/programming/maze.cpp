#include<bits/stdc++.h>
using namespace std;
struct axis
{
    int x,y;
};
queue<axis>q;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int a[155][155],cck[155][155],go[155][155];
int nx,ny,sx,sy,fx,fy;
vector<axis>v;
bool check(int x,int y)
{
    if(x<1 || y <1 || x>nx || y>ny)
        return 0;
    return 1;

}
int main()
{
    scanf("%d%d%d%d%d%d",&nx,&ny,&sx,&sy,&fx,&fy);
    int i,j;
    for(i=1; i<=nx; i++)
    {
        for(j=1; j<=ny; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    q.push({sx,sy});
    while(!q.empty())
    {
        axis t = q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            int X = t.x+x[i];
            int Y = t.y+y[i];
            if(check(X,Y)&&a[X][Y]&&!go[X][Y])
            {
                go[X][Y] = go[t.x][t.y]+1;
                q.push({X,Y});
            }
            else if(check(X,Y)&&!a[X][Y]&&!go[X][Y])
            {
                go[X][Y] = go[t.x][t.y]+1;
                v.push_back({X,Y});
            }
        }
    }
    int fn=0,cm=1e9;
//    for(i=0;i<v.size();i++){
//        printf("%d %d \n",v[i].x,v[i].y);
//    }
//return 0;
    for(i=0; i<v.size(); i++)
    {
        cck[v[i].x][v[i].y] = go[v[i].x][v[i].y];
        q.push({v[i].x,v[i].y});
        while(!q.empty())
        {
            axis t = q.front();
            //printf("cck[%d][%d]=%d\n",t.x,t.y,cck[t.x][t.y]);
            q.pop();
            if(t.x==fx&&t.y==fy)
            {
                //cout << 1;
                fn++;
                cm = min(cm,cck[fx][fy]);
                memset(cck,0,sizeof(cck));
                while(!q.empty())
                    q.pop();
            }
            else
            {
                for(j=0; j<4; j++)
                {
                    int X = t.x + x[j];
                    int Y = t.y + y[j];
                    if(check(X,Y)&&a[X][Y]&&!go[X][Y]&&!cck[X][Y])
                    {
                        //go[X][Y] = go[t.x][t.y]+1;
                        cck[X][Y] = cck[t.x][t.y]+1;
                        //out << 2;
                        q.push({X,Y});
                    }
                }
            }
        }

    }

    printf("%d\n%d",fn,cm+1);

}




