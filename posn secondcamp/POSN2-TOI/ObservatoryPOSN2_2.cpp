//https://www.proprog.tk/tasks/toi11_observatory/descs/6786
#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,j,qsum[3][2005][2005],t1,total,maxx=-1e9;
int main(){
// 0 | 1 \ 2 /
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&t1);
        qsum[0][i][j] = t1 + qsum[0][i-1][j];
        qsum[1][i][j] = t1 + qsum[1][i-1][j-1];
        qsum[2][i][j] = t1 + qsum[2][i-1][j+1];
        }
    }
    for(i=k;i<=n;i++){
        total = 0;
        for(j=1;j<=m;j++){
            if(j<k) total += qsum[1][i][j];
            else total += qsum[1][i][j] - qsum[1][i-k][j-k] - (qsum[0][i][j-k] - qsum[0][i-k][j-k]);
            if(total > maxx && j >= k) maxx = total;
        }
    }
    for(i=k;i<=n;i++){
        total = 0;
        for(j=m;j>=1;j--){
            if(j>m-k+1) total += qsum[2][i][j];
            else total += qsum[2][i][j] - qsum[2][i-k][j+k] - (qsum[0][i][j+k] - qsum[0][i-k][j+k]);
            if(total > maxx && j <= m-k+1) maxx = total;
        }
    }
    cout << maxx;

}