//https://www.codecube.in.th/task/64
#include<bits/stdc++.h>
using namespace std;
int N,a[25],i,b[25];
long long tmp4,cake,tmp2 = 1,val = 1,lcm=1,tmp3,cnt = 0;
char c;
long long gcd(long long x,long long y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d%c%d",&a[i],&c,&b[i]);
        if(a[i]>b[i]) {
        cnt += a[i]/b[i];
        a[i] = a[i]-(b[i]*(a[i]/b[i]));
        //printf("%d %d\n",a[i],b[i]);
        }
        tmp2 = gcd(lcm,b[i]);
        val  = lcm*b[i];
        lcm = (val)/tmp2;
        //printf("%d %d\n",a[i],b[i]);
    }                                                                                 
    for(i = 1 ; i <= N ; i++){
        tmp3 = lcm/b[i];
        cake += tmp3*a[i]*1ll;
    }
    tmp4 = cake;
    cake /= lcm;
    if(1ll*cake*lcm < tmp4) {
    printf("%lld\n",cake+1+cnt);
    tmp3 = gcd(lcm-(tmp4-cake*lcm*1ll),lcm);
    printf("%lld/%lld",(lcm-(tmp4-cake*lcm*1ll))/tmp3,lcm/tmp3);
    }
    else printf("%lld\n0",cake+cnt);

}