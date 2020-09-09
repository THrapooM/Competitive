#include<bits/stdc++.h>
using namespace std;
long long N,t1,t2;
long long arr[100005],i,sum = -1e9,tmp,val;
int main(){
    scanf("%lld",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%lld%lld",&t1,&t2);
        arr[i] = t2 - 2*t1;
    }
    sort(arr+1,arr+N+1);
    for(i = N ; i >= 1 ; i--){
        tmp = (i-1)*(i-1);
        val += arr[i];
        sum = max(sum,val - tmp);
    }
    printf("%lld",sum);
    

}