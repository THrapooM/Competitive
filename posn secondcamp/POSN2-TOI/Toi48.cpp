#include<bits/stdc++.h>
using namespace std;
int i,N,tim,j;
int val[5005],wei[5005];
int mem[3][5005];
bool flag;
int main(){
    scanf("%d%d",&N,&tim);
    for(i=0;i<N;i++) scanf("%d",&val[i]);
    for(i=0;i<N;i++) scanf("%d",&wei[i]);
    for(i=0;i<N;i++){
        for(j=1;j<=tim;j++){
            mem[flag][j] = mem[!flag][j];
            if(j>=wei[i]*8){
                mem[flag][j] = max(mem[flag][j],val[i]+mem[!flag][j-wei[i]*8]);
            }
        }
        flag = !flag;
    }
    printf("%d",mem[!flag][tim]);

}