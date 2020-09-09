#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y;
};
queue<axis>q;
int x[] = {0,1,0,-1};
int y[] = {-1,0,1,0};
    int n;
    int a[105][105];
int main(){
    scanf("%d",&n);
    scanf("%d%d",&sx,&sy);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",a[i][j]);
        }
    }
    q.push({sx,sy});
    while(!q.empty()){
        axis t = q.front(); q.pop();
        for(i=0;i<4;i++){
            X = t.x+x[i];
            Y = t.y+y[i];
            if(a[i][j]){

            }
        }
    }
}
