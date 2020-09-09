#include<bits/stdc++.h>
using namespace std;
map<long long,bool>mp;
int N,i;
long long t1;
int main(){
    mp[3] = 1;
    mp[7] = 1;
    mp[31] = 1;
    mp[127] = 1;
    mp[8191] = 1;
    mp[131071] = 1;
    mp[524287] = 1;
    mp[2147483647] = 1;
    mp[2305843009213693951] = 1;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%lld",&t1);
        mp[t1]==0?printf("NO\n"):printf("YES\n");
    }
}