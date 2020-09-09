#include<bits/stdc++.h>
using namespace std;
int a[105][105][3],n,m,i,j,t1,b[105][105][3],temp,sum,temp2,maxx = -1e9;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&t1);
            a[i][j][0] = t1 + a[i-1][j][0];
            a[i][j][1] = t1 + a[i][j-1][1];
            sum += t1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&t1);
            b[i][j][0] = t1 + b[i-1][j][0];
            b[i][j][1] = t1 + b[i][j-1][1];
        }
    }
    for(i=0;i<=n-1;i++){
        temp = b[i][m][1] - b[i][0][1] + b[i+2][m][1] - b[i+2][0][1];
        temp2 = a[i+1][m][1] - a[i+1][0][1];
       // printf("sum = %d temp = %d temp2 = %d\n",sum,temp,temp2);
        maxx = max(maxx,sum + temp - temp2);
    }
    //printf("\n\n");
    for(i=0;i<=m-1;i++){
        temp = b[n][i][0] - b[0][i][0] + b[n][i+2][0] - b[0][i+2][0];
        temp2 = a[n][i+1][0] - a[0][i+1][0];
      //printf("sum = %d temp = %d temp2 = %d\n",sum,temp,temp2);
        maxx = max(maxx,sum + temp - temp2);
    }
    printf("%d",maxx);

    
} 