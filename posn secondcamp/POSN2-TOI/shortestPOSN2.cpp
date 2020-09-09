#include<bits/stdc++.h>
using namespace std;
#define inf 1e9;
int a[105][105],dis[105][105];
int from,to,i,j,k;
int mx,maxx=-1e9;
float cnt,sum;
int main(){
        fill(&dis[0][0],&dis[105][0],1e9);
    while(1){
        scanf("%d%d",&from,&to);
        mx = max(from,to);
        dis[from][from] = 0;
        dis[to][to] = 0;
        maxx = max(mx,maxx);
        dis[from][to] = 1;
        if(from==0&&to==0){
            for(i=1;i<=maxx;i++){
                for(j=1;j<=maxx;j++){
                    for(k=1;k<=maxx;k++){
                        dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
                    }
                }
            }
            printf("%d\n\n",dis[1][2]);
            for(i=1;i<=maxx;i++){
                for(j=1;j<=maxx;j++){
                    if(dis[i][j]!=0&&dis[i][j]!=1e9){
                        sum += dis[i][j];
                        cnt++;
                    }
                }
            }
            cout << fixed << setprecision(3) << sum/cnt;
            return 0;
        }

    }
}