//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2078
#include<bits/stdc++.h>
using namespace std;
long long mem[10005];
int i,j,n,cube[25];
int main(){
    for(i=1;i<=21;i++){
        cube[i] = i*i*i;
    }
    mem[0] = 1;
    for(i=1;i<=21;i++){
        for(j=cube[i];j<10000;j++){
            mem[j] += mem[j-cube[i]];
        }
    }
    while(cin >> n){
        printf("%lld\n",mem[n]);
    }
}
