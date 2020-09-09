#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,z,cnt;
struct axis{
        int x,y;
};
queue<axis>q;
vector<axis>v;
queue<axis>nq;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
char c;
int wa[70][70],minn,tree[70][70];
int a[70][70],minnn=1e9,b;
bool r = false,mem[70][70],mem1[70][70];
int main(){
    scanf("%d%d",&n,&m);
    minn = min(n,m);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf(" %c",&c);
            if(c=='T') tree[i][j]= 1;
            tree[i][j] += tree[i-1][j]+tree[i][j-1]-tree[i-1][j-1];
            if(c=='P') wa[i][j] = 1;
            }
    }
   for(i=1;i<=m;i++){
       for(j=1;j<=n;j++){
           printf("%d",tree[i][j]);
       }
       printf("\n");
   }
    //n=8 m =6
    for(z=minn;z>=1;z--){
            for(i=1;i+z-1<=m;i++){
                for(j=1;j+z-1<=n;j++){
                    if(tree[i+z-1][j+z-1]-tree[i-1][j+z-1]-tree[i+z-1][j-1]+tree[i-1][j-1]==0){
                           cnt++;
                           v.push_back({i,j});
                    }
                }
            }
            if(cnt) break;

    }
    cnt = 0;
//    printf("%d %d %d %d %d",i,j,i+z-1,j+z-1,z);
//   for(i=0;i<v.size();i++){
//    printf("%d %d\n",v[i].x,v[i].y);
//   }
   for(int k=0;k<v.size();k++){
     //   q.push({v[k].x,v[k].y});
        for(i=v[k].x;i<v[k].x+z;i++){
            for(j=v[k].y;j<v[k].y+z;j++){
                if(wa[i][j]&&!mem[i][j]){
                    cnt++;
                    q.push({i,j});
                    while(!q.empty()){
                        axis t = q.front(); q.pop();
                        for(b=0;b<4;b++){
                            int X = t.x+x[b];
                            int Y = t.y+y[b];
                            if(!mem[X][Y]&&X>=v[k].x&&Y>=v[k].y&&X<=m&&Y<=n&&wa[X][Y]){
                                mem[X][Y] = true;
                                q.push({X,Y});
                            }
                        }
                    }
                }
            }
        }
        minnn = min(minnn,cnt);
        memset(mem,false,sizeof(mem));
        cnt = 0;
        }

    if(minnn==1e9) minnn=0;
    printf("%d %d\n",z*z,minnn);
}

