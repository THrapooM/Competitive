#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,ey,ex;
int mem[305][305][4],symbol[305][305][4];
char way[305][305],c;
struct axis{
    int x,y,che;
}t;
queue<axis>que,mp;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&c);
            if(c=='S') que.push({i,j,0});
            else if(c=='E') ey = i,ex = j;
            if(c!='/' && c!='-' && c!='\\' && c!='|') way[i][j] = c;
            else if(c!='.' && c!='#'){
                symbol[i][j][0] = 1;
                mp.push({i,j,0});
                mp.push({i,j,1});
                mp.push({i,j,2});
                mp.push({i,j,3});
            }
        }
    }
    while(!mp.empty()){
        t = mp.front(); mp.pop();
        if
    }
    
}