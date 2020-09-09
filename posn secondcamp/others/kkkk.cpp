#include<bits/stdc++.h>

using namespace std;


int h[] = {0,1,0,-1},
    k[] = {1,0,-1,0};
int mem[4][1005][1005];
int a[1005][1005];

struct n
{
    int direc,x,y;
};
queue<n> q;
int main()
{
    int n;
    int i,j;
    cin >> n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    q.push({0,0,0});
    q.push({1,0,0});
    int c,direc,x,y;
    while(!q.empty())
    {
        c=0;
        direc = q.front().direc;
        x = q.front().x;
        y = q.front().y;
        printf("mem[%d][%d][%d] = %d\n",direc,x,y,mem[direc][x][y]);
        q.pop();
        if(x==n-1&&y==n-1)
        {
            cout << mem[direc][x][y];
            break;
        }
        int X = x+h[direc], Y = y+k[direc];
        if (X >= 0 && X < n && Y >= 0 && Y < n && !a[X][Y] && !mem[direc][X][Y]){
            mem[direc][X][Y] = mem[direc][x][y]+1;
            q.push({direc,X,Y});
        }
        else {
            for(i=1;i<4;i++)
            {
                if(a[x+h[(direc+i)%4]][y+k[(direc+i)%4]]!=1&&mem[(direc+i)%4][x][y]==0 && x+h[(direc+i)%4] >= 0 && x+h[(direc+i)%4] < n && y+k[(direc+i)%4] >= 0 && y+k[(direc+i)%4] < n)
                {
                    //cout << 1;
                    mem[(direc+i)%4][x+h[(direc+i)%4]][y+k[(direc+i)%4]] = mem[direc][x][y]+1;
                    q.push({(direc+i)%4,x+h[(direc+i)%4],y+k[(direc+i)%4]});
                }
            }
        }
    }
}
