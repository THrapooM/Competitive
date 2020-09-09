#include<bits/stdc++.h>
using namespace std;
long long N,i,l,r,j;
long long sum,findsum,ft,st,tt,val,sm = 1e17,maxx= 0,minn = 1e17,a[125000],qs[125000];
long long vall,valr;
int main(){
    scanf("%lld",&N);
    for(i=1;i<=N;i++){
        scanf("%lld",&a[i]);
        qs[i] = qs[i-1] + a[i];
        minn = min(minn,a[i]);
        maxx = max(maxx,a[i]);
        sum += a[i];
    }
    if(N<=100){
        for(i=1;i<N-1;i++){
            for(j=i+1;j<N;j++){
                maxx = max(qs[i],max(qs[j]-qs[i],qs[N]-qs[j]));
                minn = min(qs[i],min(qs[j]-qs[i],qs[N]-qs[j]));
                sm = min(sm,maxx-minn);
            }
        }
        printf("%lld",sm);
        return 0;
    }
    l = 1,r = N;
    while(l<=r){
        if(vall + a[l] < valr + a[r]){
            sum -= a[l];
            vall += a[l++];
        }
        else {
            sum -= a[r];
            valr += a[r--];
        }
        ft = vall;
        st = sum;
        tt = valr;
        maxx = max(ft,max(st,tt));
        minn = min(ft,min(st,tt));
        sm = min(sm,maxx-minn); 
       // printf("ft = %lld st = %lld tt = %lld maxx = %lld minn = %lld sm  = %lld\n",ft,st,tt,maxx,minn,sm);
    }  
    printf("%lld",sm);

}