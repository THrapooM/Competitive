//https://www.codecube.in.th/task/72
#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,t1;
bool path[505][505];
int a[505][505];
int main(){
    scanf("%d%d",&n,&m);
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0) path[i][j] = true;
            else path[i][j] = false;
        }
    }
    
}