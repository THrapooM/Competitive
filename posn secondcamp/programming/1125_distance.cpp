#include<bits/stdc++.h>
using namespace std;
int N;
long long x[500005],y[500005],i;
long long int resx,resy,sumx,sumy;
int main(){
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++)
        scanf("%lld%lld",&x[i],&y[i]);
    sort(x,x+N);
    sort(y,y+N);
    for(i = 0 ; i < N ; i++){
        resx += (x[i]*i*1ll - sumx);
        sumx += x[i];
        resy += (y[i]*i*1ll - sumy);
        sumy += y[i];
    }
    printf("%lld",resx+resy);
}