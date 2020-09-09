#include<bits/stdc++.h>
using namespace std;
int n,num,j,mem[1<<14+3],temp,k;
int main(){
    scanf("%d",&n);
    for(num=0;num<(1<<n);num++){
        mem[num] = 1;
        for(j=0;j<n;j++){
            temp = num|1<<j;
            if(!mem[temp]&&temp!=num){
                for(k=n-1;k>=0;k--){
                    if(num&(1<<k)) printf("1");
                    else printf("0");
                }
                printf(" ");
                for(k=n-1;k>=0;k--){
                    if(temp&(1<<k)) printf("1");
                    else printf("0");
                }
                printf("\n");
            }
        }
    }
}