#include<bits/stdc++.h>
using namespace std;
int C[] = {1,3,4,5};
int temp;
bool visited[100005];
int dp[100005];
int INF = 1e9;
int coin_change(int x){
    if(x==0) return 0;
    if(visited[x]) return dp[x];
    visited[x] = true;
    dp[x] = INF;
    for(int i=0;i<4;i++){
        if(C[i]<=x) dp[x] = min(coin_change(x-C[i])+1,dp[x]);
    }
    return dp[x];
}
int main()
{
    int n;
    scanf("%d",&n);
    cout << coin_change(n);
    return 0;
}
