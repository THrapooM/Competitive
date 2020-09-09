#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,a[305][305];
struct axis{
    int x,y;
}t;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int path[305][305][5],t1;
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&t1);
            if(t1==21){ path[i][j][0] = path[i][j][2] = true;} 
            else if(t1==11){path[i][j][0] = path[i][j][3] = true;}
            else if(t1==)
        }
    }
}