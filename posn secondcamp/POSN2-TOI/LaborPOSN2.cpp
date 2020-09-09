//https://www.proprog.tk/tasks/toi11_labor/descs/6787
#include<bits/stdc++.h>
using namespace std;
unsigned long long r = 1e19,mid,t1,t2,l,a[1000005],i,N,k;
bool kuri(unsigned long long x){
    unsigned long long tmp=0;
    for(int i=0;i<N;i++){
        tmp += (unsigned long long)(x/a[i]);
        if(tmp>=k) return 1;
    }
    if(tmp<k) return 0;
    //return 1;
}
int main(){
    scanf("%llu%llu",&N,&k);
    for(i=0;i<N;i++){
        //sum += a[i];
        scanf("%llu",&a[i]);
    }
   sort(a,a+N);
    while(l<=r){
        //cout << mid << endl;
        mid = (l+r)>>1ll;
        t1 = kuri(mid); t2=kuri(mid-1);
        if(t1&&!t2){
            printf("%llu",mid); return 0;
        }
        else if(t1&&t2) r = mid-1;
        else l = mid+1;
        //cout << 1;
    }
}