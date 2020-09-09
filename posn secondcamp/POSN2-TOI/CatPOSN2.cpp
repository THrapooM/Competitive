#include<bits/stdc++.h>
using namespace std;
long long r,mx=-1e9,a[2000005] ;
int i,l,mid,N;
bool cat (long long x){
     long long check = 0;
     bool che = 0;
    for(int i=1;i<=N;i++){
        if(x>=a[i]) continue;
        else {
            if(che==0){
                check = a[i];
            }
            else if(che==1){
                if(check!=a[i])
                return 0;
           }
        che = !che;
        }
    }
    return 1;
}
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%lld",&a[i]);
        //mi = min(mi,a[i]);
        mx = max(mx,a[i]);
    }
    l = 1,r = mx+1;
    while(l<=r){
      //   cout << mid << " " << l << " "<< r << endl;
        mid = (l+r)>>1;
        if(cat(mid)&&!cat(mid-1)){
            printf("%d",mid); return 0;
        }
        // if (cat(mid-1) && !cat(mid)){
        //     printf("%d",mid-1);return 0;
        // }
        else if(cat(mid)&&cat(mid-1)){
            r = mid-1;
        }
        else l = mid+1;
    }
    cout <<0;
}