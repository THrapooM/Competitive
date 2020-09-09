#include<bits/stdc++.h>
using namespace std;
int arr[100005],dp[100005];
int N,pos,t1,l,r,mid,i,maxx = -1e9;
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&arr[i]);
    }
    for(i = 1 ; i <= N ; i++){
        if(arr[i] >= arr[i-1]) dp[i] += dp[i-1] + 1,maxx = max(maxx,dp[i]);
        else dp[i] = 1,maxx = max(maxx,dp[i-1]);
    }
    //for(i = 1 ; i <= N ; i++) printf("dp[%d] = %d\n",i,dp[i]);
    printf("%d",maxx);    
}