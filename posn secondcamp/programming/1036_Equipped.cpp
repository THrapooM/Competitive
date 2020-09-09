#include<bits/stdc++.h>
using namespace std;
int n,k,check,i,j,t1;
int used[10005],val[10005],mem[1<<8+5];
int equip(int row,int che){
    if(che==check) return 0;
    if(mem[che]) return mem[che];
    mem[che] = 1e9;
    for(int i = 0; i < n ; i++){
        mem[che] = min(mem[che],val[i]+equip(row+1,che|used[i]));
    //    printf("row = %d i = %d che = %d\n",row,i,che);
    }
    return mem[che];
}
int main(){
    scanf("%d%d",&n,&k);
    check = (1 << k)-1;
    for(i=0;i<n;i++){
        scanf("%d",&val[i]);
        for(j=0;j<k;j++){
            scanf("%d",&t1);
            if(t1) used[i] |= 1 << j;
        }
    }
    //for(i=0;i<n;i++) printf("used[%d] = %d\n",i,used[i]);
    printf("%d",equip(0,0));
}