// #include<bits/stdc++.h>
// using namespace std;
// int n,m,k,i,sum;
// int  mem[50005][1005];
// int a[50005];
// int  qs[50005];
// int qsum(int x,int y){
//     return qs[y] - qs[x-1];
// }
// int  destruct(int pos,int punch){
//         if(pos==n+1 || punch==m) return 0;
//         if(punch > m) return mem[pos][punch] = 1e9;
//         if(mem[pos][punch]) return mem[pos][punch];
//         int temp = 0;
//         mem[pos][punch] = 1e9;
//         for(int i = k;i <= n && pos+i-1 <=n ;i++){
//             temp = qsum(pos,pos+i-1);
//             mem[pos][punch] = min(mem[pos][punch],min(destruct(pos+1,punch),destruct(pos+i,punch+1)+temp));
//             //printf("temp = %d pos = %d pos+i-1 = %d mem[%d][%d] = %d\n",temp,pos,pos+i-1,pos,punch,mem[pos][punch]);
//         }
//         return mem[pos][punch];
// }
// int main(){
//     //fill(&mem[0][0],&mem[50004][1004],1e9);
//     scanf("%d%d%d",&n,&m,&k);
//     for(i=1;i<=n;i++){
//         scanf("%d",&a[i]);
//         sum += a[i];
//         qs[i] = a[i] + qs[i-1];
//     }
//     // printf("%d",destruct(1,0));
//     // printf("\n\n");
//     printf("%d",sum-destruct(1,0));  
// }
#include<bits/stdc++.h>
using namespace std;
long long t1,dp[2][100005],pmin[2][100005],qs[100005],sum;
int main(){
    int N,M,K,i,j;
    pmin[0][0] = 1e17;
    bool flag = true;
    scanf("%d%d%d",&N,&M,&K);
    for(i = 1 ; i <= N ; i++){
        scanf("%lld",&t1);
        qs[i] = qs[i-1] + t1;
        pmin[0][i] = min(pmin[0][i-1],-qs[i-1]);
        sum += t1;
    }
    for(i = 1 ; i <= M ; i++){
        dp[flag][0] = 1e17;
        pmin[flag][0] = 1e17;
        for(j = 1 ; j <= N ; j++){
            dp[flag][j] = dp[flag][j-1];
            if(j-K>=0) dp[flag][j] = min(dp[flag][j],pmin[!flag][j-K+1]+ qs[j]);
            pmin[flag][j] = min(pmin[flag][j-1],dp[flag][max(j-2,0)]-qs[j-1]);
        }
        flag = !flag;
    }
    printf("%lld",sum-dp[!flag][N]);
}