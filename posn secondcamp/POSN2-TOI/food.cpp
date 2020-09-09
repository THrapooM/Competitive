#include<bits/stdc++.h>
using namespace std;
int N,k,i,a[10],t1,b[10],che;
void food(int use, int cpf){
        if(use==N+1){
            for(int i = 1; i<=N;i++){
                printf("%d ",b[i]);
            }
            printf("\n");
            return ;
        }
        for(int j = 1 ; j <= N ; j++){
            if(use==1&&cpf!=j) continue;
            if(((1<<j)&che)) continue;
            che |= 1 << j;
            b[use] = j;
            food(use+1,cpf);
            che ^= 1 << j;
        }
}
int main(){
    scanf("%d%d",&N,&k);
    for(i = 1; i <= k ; i++){
        scanf("%d",&t1);
        a[t1] = true; 
    }
    for(i = 1 ; i <= N ; i++){
        if(!a[i]) food(1,i);
    }
}