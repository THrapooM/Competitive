#include<bits/stdc++.h>
using namespace std;
int tpk[100005],i,j;
int main(){
    for(i=1;i<=100000;i++){
        for(j=1;j<=sqrt(i);j++){
            if(i%j==0) tpk[i]++;
        }
    }
    for(i=1;i<=30;i++){
        printf("tpk[%d] = %d\n",i,tpk[i]);
    }
}