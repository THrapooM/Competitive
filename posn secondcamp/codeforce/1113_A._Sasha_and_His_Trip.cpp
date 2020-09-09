#include<bits/stdc++.h>
using namespace std;
int N,M,fuel,i,dollar;
int main(){
    scanf("%d%d",&N,&M);
    if(N-1<=M) {printf("%d",N-1); return 0;}
    fuel = N-1;
    fuel = min(N-1,M);
    dollar = fuel;
    for(i = 2 ; i < N ; i++){
        fuel--;
        if(fuel+i==N) continue;
        fuel++;
        dollar += i;
  }   
    printf("%d",dollar);
}