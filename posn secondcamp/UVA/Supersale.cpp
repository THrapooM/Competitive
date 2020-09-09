//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1071
#include<bits/stdc++.h>
using namespace std;
int mem[1005][35],wei[1005],val[1005],cnt,n,m,k,t1,i;
int knap(int x,int cap){
    if(x==m || cap==0) return 0;
    if(mem[x][cap]) return mem[x][cap];
    mem[x][cap] = knap(x+1,cap);
    if(wei[x]<=cap){
       return mem[x][cap] = max(mem[x][cap],val[x]+knap(x+1,cap-wei[x]));
    }
    return mem[x][cap];
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d",&val[i],&wei[i]);
        }
        scanf("%d",&k);
        for(i=0;i<k;i++){
            scanf("%d",&t1);
           cnt += knap(0,t1);

        }
        printf("%d\n",cnt);
        memset(mem,0,sizeof(mem));
        memset(val,0,sizeof(val));
        memset(wei,0,sizeof(wei));
        cnt = 0;
    }
}
