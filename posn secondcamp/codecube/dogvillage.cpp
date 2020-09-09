#include<bits/stdc++.h>
using namespace std;
struct axis
{
    int x,y;
};
int n,m;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int X,Y,Z;
int i,j,k;
int w[1005][1005];
char W[1005][1005];
int mem[1005][1005];
queue <axis> q;
bool check(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    return 1;
}
int main()
{

    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&w[i][j]);
            if(w[i][j]==0)
                {q.push({i,j});
                w[i][j]='D';
                W[i][j]='D';
                mem[i][j]=1;
                }
        }
    }
    int k=0,p=0;
    while(1)
    {
        while(!q.empty())
        {
            axis t = q.front();
            q.pop();
            for(i=0; i<4; i++)
            {
                X = t.x +x[i];
                Y = t.y +y[i];
                if(check(X,Y)&&w[X][Y]!=1&&w[X][Y]!=0)
                {
                    w[X][Y] = 'D';
                    W[X][Y] = 'D';
                }
            }
        }
        for(k=0; k<n; k++)
        {
            for(p=0; p<m; p++)
            {
                if(W[k][p]=='D'&&mem[k][p]==0) {q.push({k,p});
                mem[k][p]= 1;
                }
                else if(W[k][p]!='D'&&w[k][p]!=0) w[k][p]-=1;
            }
        }
        if(q.empty()) break;
    }
int count=0;
for(i=0; i<n; i++)
{
    for(j=0; j<m; j++)
    {
        if(W[i][j]=='D') count++;
    }
}
   // printf("%d",count);
     printf("%d",(n*m)-count);
}

