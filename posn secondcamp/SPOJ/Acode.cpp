#include<bits/stdc++.h>
using namespace std;
string s;
int x,i,fc,sc;
long long dp[5005];
int main(){
    while(cin >> s){
        if(s[0]=='0') return 0;
        x = s.length();
        memset(dp,0,sizeof(dp));
        dp[0] = dp[1] = 1;
        for(i=2;i<=x;i++){
            fc = s[i-2]-'0',sc = s[i-1]-'0';
            if(fc== 1 || (fc==2 && sc <=6))dp[i] += dp[i-2];
            if(sc!=0) dp[i]+= dp[i-1];
        }
        printf("%lld\n",dp[x]);
    }
}