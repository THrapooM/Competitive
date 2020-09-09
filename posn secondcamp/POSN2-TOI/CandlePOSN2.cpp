#include<bits/stdc++.h>
using namespace std;
int i,n,m,j;
bool a[2005][2005];
bool mem[2005][2005];
struct axis{
    int x,y;
}t;
queue<axis>q;
char s[2005];
int cnt;
int x[] = {0,1,0,-1,1,1,-1,-1};
int y[] = {1,0,-1,0,1,-1,1,-1};
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",s);
        for(j=0;j<m;j++){
            if(s[j]=='1') a[i][j+1]= 1;
        }
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!mem[i][j]&&a[i][j]){
                    //printf("i = %d j =  %d\n",i,j);
                    cnt++;
                    mem[i][j] = true;
                    q.push({i,j});
                    while(!q.empty()){
                        t = q.front(); q.pop();
                        printf("%d %d %d\n",t.x,t.y,mem[t.x][t.y]);
                     //   cout << 1;
                        for(int k=0;k<8;k++){
                            int X = t.x+x[k];
                            int Y = t.y+y[k];
                            if(!mem[X][Y]&&a[X][Y]){
                                mem[X][Y] = true;
                                q.push({X,Y});
                            }
                        }
                    }
            }
        }
    }
    cout << cnt;
}
