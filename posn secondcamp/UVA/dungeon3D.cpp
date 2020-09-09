#include<bits/stdc++.h>
using namespace std;
struct axis
{
    int x,y,z;
};
int x[] = {-1,1,0,0,0,0};
int y[] = {0,0,-1,1,0,0};
int z[] = {0,0,0,0,-1,1};
int X,Y,Z;
int i,j,k;
int fi,fj,fk;
int ei,ej,ek;
queue <axis> q;
int n,w,l,checkk;
bool check(int x,int y,int z)
{
    if(x < 0 || y < 0 || z < 0 || x >= n || y >= w || z >=l )
        return 0;
    return 1;
}
int main()
{
    while(cin >> n >> w >> l) {
        char m[35][35][35] ={};
        int M[35][35][35] = {};
        if(!n && !w && !l) return 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<w; j++)
            {
                for(k=0; k<l; k++)
                {
                    scanf(" %c",&m[i][j][k]);
                    if(m[i][j][k]=='S')
                    {
                        fi = i;
                        fj = j;
                        fk = k;
                    }
                    else if(m[i][j][k]=='E')
                    {
                        ei = i;
                        ej = j;
                        ek = k;
                    }
                }
            }
        }
        q.push({fi,fj,fk});
        while(!q.empty())
        {
            axis t = q.front();
            q.pop();
            for(i=0; i<6; i++)
            {
                X = t.x + x[i];
                Y = t.y + y[i];
                Z = t.z + z[i];
                if(check(X,Y,Z)&&m[X][Y][Z]!='#'&&!M[X][Y][Z])
                {
                    q.push({X,Y,Z});
                    M[X][Y][Z] = M[t.x][t.y][t.z]+1;
                }
            }
        }
        if(M[ei][ej][ek]) printf("Escaped in %d minute(s).\n",M[ei][ej][ek]);
        else printf("Trapped!\n");
    }
}
