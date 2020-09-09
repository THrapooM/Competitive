#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,anss,ans[5];
string s1;
int a[1005][1005];
bool visited[1005][1005];
struct axis{
    int x,y;
}t;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int X,Y;
queue<axis>q;
bool check(int co1,int co2){
    int cnt = 0;
    cnt += a[co1-1][co2];
    cnt += a[co1][co2-1];
    cnt += a[co1][co2+1];
    cnt += a[co1+1][co2];
    if(cnt==1) return true;
     return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        cin >> s1;
        for(j=1;j<=n;j++){
            a[i][j] = s1[j-1]-'0';
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[i][j]==1 && !visited[i][j]){
            visited[i][j] = true; 
            q.push({i,j});
            while(!q.empty()){
                t = q.front(),q.pop();
                if(check(t.x,t.y)) anss++;
                for(int k=0;k<4;k++){
                    X = t.x + x[k];
                    Y = t.y + y[k];
                    if(!visited[X][Y] && a[X][Y]){
                        visited[X][Y] = true;
                        q.push({X,Y});
                    }
                }
            }
            if(anss==0) ans[0]++;
            else if(anss==3) ans[2]++;
            else if(anss==4) ans[1]++; 
            anss = 0;
        }
        }
    }
    for(i=0;i<3;i++) printf("%d ",ans[i]);
}