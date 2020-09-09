#include<bits/stdc++.h>
using namespace std;
int N,dp[4005],arr[5],i;
int main(){
    scanf("%d%d%d%d",&N,&arr[0],&arr[1],&arr[2]);
    dp[arr[0]] = dp[arr[1]] = dp[arr[2]] = true;
    for(i = 1 ; i <= N ; i++){
        if(i >= arr[0] && dp[i - arr[0]]){
            dp[i] = max(dp[i],dp[i-arr[0]]+1);
        }
         if(i >= arr[1] && dp[i - arr[1]]){
            dp[i] = max(dp[i],dp[i-arr[1]]+1);
        }
         if(i >= arr[2] && dp[i - arr[2]]){
            dp[i] = max(dp[i],dp[i-arr[2]]+1);
        }
    }
    printf("%d",dp[N]);

}