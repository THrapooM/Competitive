#include<bits/stdc++.h>
using namespace std;
int area[1005][1005];
int i,j,n,m,k,maxx=-1e9;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&area[i][j]);
            area[i][j] = area[i][j] + area[i-1][j] + area[i][j-1]-area[i-1][j-1];
        }
    }
    for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            maxx = max(maxx,area[i][j]-area[i-k][j]-area[i][j-k]+area[i-k][j-k]);
        }
    }
    cout << maxx;
}