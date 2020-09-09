#include<bits/stdc++.h>
using namespace std;
int Tc;
long long N,K;
int main(){
    scanf("%d",&Tc);
    while(Tc--){
        scanf("%lld%lld",&N,&K);
        long long cnt = 0,tmp;
        while(N){
            tmp = N%K;
            if(tmp){
                N -= tmp;
                cnt += tmp;
            }
            else {
                N /= K;
                cnt++;
            }
        }
        printf("%lld\n",cnt);
    }
}