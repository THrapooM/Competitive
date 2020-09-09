//www.codecube.in.th/task/48
#include<stdio.h>
using namespace std;
int cost[505],n,mem[2][50005],i,lm,j;
bool flag=true;
int main(){
    scanf("%d%d",&n,&lm);
    for(i=0;i<n;i++){
        scanf("%d",&cost[i]);
    }
    mem[0][0] = 1;
    for(i=0;i<n;i++){
        for(j=0;j<=lm;j++){
            mem[flag][j] = mem[!flag][j]%1000007;
            if(j>=cost[i]){
                mem[flag][j] = (mem[flag][j]+mem[!flag][j-cost[i]])%1000007;
            }
        }
        flag = !flag;
    }
    printf("%d",mem[!flag][lm]);

}
