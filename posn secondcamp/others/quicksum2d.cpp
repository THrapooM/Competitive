#include<bits/stdc++.h>
using namespace std;
int i,j,k;
int a[105][105];
int fx,fy,ex,ey;
int main(){
    int n;
    scanf("%d%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            }
    }
//    scanf("%d%d%d%d",&fx,&fy,&ex,&ey);
//    cout << a[ey][ex]-a[ey][fx-1]-a[fy-1][ex]+a[fy-1][fx-1];
for(i=1;i<=n;i++{
    for(j=1;j<=n;j++){
        printf("%d",a[i][j]);
    }
    printf("\n");
})



}
