#include<bits/stdc++.h>
using namespace std;
int tc,i,N,M,tmp;
int main(){
    scanf("%d",&tc);
    for(i = 1 ; i <= tc ; i++){
        scanf("%d%d",&N,&M);
        if(M>N) M = N;
        printf("Case #%d: %d \n",i,M/20+1);
    }
}