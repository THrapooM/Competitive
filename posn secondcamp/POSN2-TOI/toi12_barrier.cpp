#include<bits/stdc++.h>
using namespace std;
long long N,arr[6000005],i,siz,ans1,ans2,tx,tval;
struct axis{
    long long x,val;
};
deque<axis>deq;
int main(){
    scanf("%lld%lld",&N,&siz);
    for(i = 1 ; i <= N ; i++)
    scanf("%lld",&arr[i]),arr[i] += arr[i-1];
    if(N==1 && arr[1] > 0 ) {printf("%lld\n%lld",arr[1],1); return 0;}
    deq.push_front({1,0});
    for(i = 2 ; i <= N ; i++){
        while(i - deq.front().x >= siz) deq.pop_front();
        while(!deq.empty() && arr[i-1] <= deq.back().val) deq.pop_back();
        deq.push_back({i,arr[i-1]});
         tx = i - deq.front().x + 1;
         tval = arr[i] - deq.front().val;
        if(tval > ans1) ans1 = tval,ans2 = tx;
        else if(tval == ans1 && tx <= ans2) ans2 = tx;
    }
    printf("%lld\n%lld",ans1,ans2);
}