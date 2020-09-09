//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=662&page=show_problem&problem=3342
#include<bits/stdc++.h>
using namespace std;
int n,m,total,l,r,mid,mi;
int coin[3] = {2*100,3*9900,5*990000};
int change[3] = {2,3,5};
int watt[3] = {100,9900,990000};
int moneytowatt(int K){
    int wh = 0;
    for(int i=0;i<3;i++){
        if(K>=coin[i]){
            wh += coin[i]/change[i];
            K -= coin[i];
        }
        else if(K<coin[i]){
            wh += K/change[i];
            K  = 0;
        }
    }
    if(K) wh += K/7;
    return wh;
}
int wattomoney(int Z){
    int price = 0;
    for(int i=0;i<3;i++){
        if(Z>=watt[i]){
            price += watt[i]*change[i];
            Z -= watt[i];
        }
        else if(Z<watt[i]){
            price += Z*change[i];
            Z = 0;
        }
    }
    if(Z) price += Z*7;
    return price;
}
int main(){
    while(cin >> n >> m)
    {   if(!n && !m) return 0;
        total = moneytowatt(n);
        l = 0; r = total;
        while(1){
            mid = (l+r)>>1;
            if(abs(wattomoney(mid)-wattomoney(total-mid))==m) {mi = min(mid,total-mid);break;}
            else if(abs(wattomoney(mid)-wattomoney(total-mid))>m) r = mid-1;
            else if(abs(wattomoney(mid)-wattomoney(total-mid))<m) l = mid+1;
        }
        printf("%d\n",wattomoney(mi));
    }
}