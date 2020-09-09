//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293
#include<bits/stdc++.h>
using namespace std;
int i,j,n;
int coin[5] = {1,5,10,25,50};
long long mem[30005];
int main(){
    mem[0] = 1;
    for(i=0;i<5;i++){
        for(j=coin[i];j<=30000;j++){
            mem[j]+=mem[j-coin[i]];
        }
    }
    
     while(scanf("%d",&n)!=EOF){
        if(mem[n]==1){
           printf("There is only 1 way to produce %d cents change.\n",n); 
        }
        else printf("There are %d ways to produce %d cents change.\n",mem[n],n);
    }
}