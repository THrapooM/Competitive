#include<bits/stdc++.h>
using namespace std;
map<long long,bool>mymap;
int N;
long long t1;
void sieve(long long n){
    for(long long i=2;i*i<=n;i++){
        if(mymap[i]==false){
            for(long long j=i*i;j<=n;j+=i)
            mymap[i] = true;
        }
    }
}
bool  M_prime(long long n){
        if(n/2==0) return 1;
        return 0;
}
int main(){
    sieve(LLONG_MAX);
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%lld",&t1);
        if(!mymap[t1]&&M_prime(t1+1)) printf("YES\n");
        else printf("NO\n");
    }
}