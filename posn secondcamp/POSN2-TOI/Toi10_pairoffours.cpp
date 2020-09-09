// #include<bits/stdc++.h>
// using namespace std;
// int N,i,mem[1005][1005];
// char x[1005];
// int mcm(int l,int r){
//     if(l >= r) return 0;
//     if(mem[l][r]) return mem[l][r];
//     for(int i = l ; i < r ; i++)  mem[l][r] = max(mem[l][r],mcm(l,i)+mcm(i+1,r));
//     if(x[l]==x[r]) mem[l][r] = max(mem[l][r],mcm(l+1,r-1)+1);
//    // printf("mem[%d][%d] = %d\n",l,r,mem[l][r]);
//     return mem[l][r];
// }
// int main(){
//     scanf("%d",&N);
//     for(i = 0 ; i < N ; i++) scanf(" %c",&x[i]);
//     printf("%d",mcm(0,N-1));
// }
#include<bits/stdc++.h>
using namespace std;
int i,N,l,r,dp[1005][1005],j,k;
char x[1005];
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++) scanf(" %c",&x[i]);
    for(i = 2 ; i <= N ; i++){
        for(l = 1 ; l <= N - i + 1 ; l++){
            r = l + i - 1;
            for(k = l ; k < r ; k++) dp[l][r] = max(dp[l][r],dp[l][k]+dp[k+1][r]);
            if(x[l]==x[r]) dp[l][r] = max(dp[l][r],dp[l+1][r-1]+1);
    }
    }
    printf("%d",dp[1][N]);
}