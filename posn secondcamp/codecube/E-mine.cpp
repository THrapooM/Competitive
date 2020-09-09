// #include<bits/stdc++.h>
// using namespace std;
// int N,K,i,j;
// int a[505][505],mem[505][505][55];
// int emine(int x,int y,int walk){
//     if(x==N+1 || y== N+1) return 0;
//     if(mem[x][y][walk]) return mem[x][y][walk];
//     mem[x][y][walk] = max(mem[x][y][walk],emine(x+1,y,0));
//     mem[x][y][walk] = max(mem[x][y][walk],emine(x,y+1,0));
//     if(walk < K) mem[x][y][walk] = max(mem[x][y][walk],max(a[x][y] + emine(x+1,y,walk+1),a[x][y] + emine(x,y+1,walk+1)));
//     printf("mem[%d][%d][%d] = %d\n",x,y,walk);
//     return mem[x][y][walk];
// }
// int main(){
//     scanf("%d%d",&N,&K);
//     for(i = 1 ; i <= N ; i++)
//         for(j = 1 ; j <= N ; j++)
//             scanf("%d",&a[i][j]);
//    printf("%d",emine(1,0,0));
// }
#include<bits/stdc++.h>
using namespace std;
int N,K,i,j,k,t;
int dp[2][505][55],ans;
bool flag;
int main(){
    scanf("%d%d",&N,&K);
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= N ; j++){
            scanf("%d",&t);
            for(k = 0 ; k <= K ; k++){
                dp[flag][j][k] = 0;
                if(k){
                    dp[flag][j][k] = max(dp[flag][j][k],dp[!flag][j][k-1] + t);
                    dp[flag][j][k] = max(dp[flag][j][k],dp[flag][j-1][k-1] + t);
                }
                dp[flag][j][k] = max(dp[flag][j][k],dp[!flag][j][K]);
                dp[flag][j][k] = max(dp[flag][j][k],dp[flag][j-1][K]);
            }
        }
            flag = !flag;
    }
    for(k = 0 ; k <= K ; k++) ans = max(ans,dp[!flag][N][k]);
    cout << ans;
}