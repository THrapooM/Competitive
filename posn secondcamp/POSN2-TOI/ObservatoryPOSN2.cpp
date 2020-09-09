//ver.noob
#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,j,a[2005][2005],t,diag1,diag2,maxx=-1e9;
int store[3][2005][2005],sum;
void check(){
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
     printf("\n\n");
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%3d ",store[1][i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%3d ",store[2][i][j]);
        }
        printf("\n");
    }
}
int main(){
     // 0 2d 1 / 2 \ //
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            store[0][i][j] += a[i][j] + store[0][i][j-1] +store[0][i-1][j] - store[0][i-1][j-1];
            store[1][i][j] += a[i][j] + store[1][i-1][j+1];
            store[2][i][j] += a[i][j] + store[2][i-1][j-1];
        }
    }
 //check();
      for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            sum = store[0][i][j] - store[0][i-k][j] - store[0][i][j-k] +store[0][i-k][j-k];
            diag1 = sum;
            diag2 = sum;
            int x = j;
            for(t=i-1;t>=i-k+1;t--){
                diag1 -= store[1][t][j-k+1] -store[1][i-k][x--];
                diag2 -= store[2][t][j] -store[2][i-k][j+i-k-t];
            }
       // printf("sum = %d i = %d j = %d %d %d\n",sum,i,j,diag1,diag2);
            maxx = max(maxx,max(diag1,diag2));
        }
    }
    cout << maxx;
}