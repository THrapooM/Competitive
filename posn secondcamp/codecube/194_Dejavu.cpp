#include<bits/stdc++.h>
using namespace std;
long long dp[100005],i,N,t1,sum,now,sum1,pos,j,tmp; 
vector<long long>v[100005]; 
int main(){
    scanf("%lld",&N);
    for(i = 0 ; i < N ; i++){
        scanf("%lld",&t1);
        auto pos = upper_bound(dp,dp+now,t1) - dp;
        if(pos==now) now++;
        dp[pos] = t1;
        v[pos].push_back(t1);
    }
    sum = v[now-1][0];
    tmp = sum;
    for(i = now-2 ; i >= 0 ; i--){
            for(j = 0 ; j < v[i].size() ; j++){
                if(v[i][j] <= tmp){
                    sum += v[i][j];
                    tmp = v[i][j];
                    break;
                }
            }
    }
    printf("%lld %lld",now,sum);
}