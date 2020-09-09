#include<bits/stdc++.h>
using namespace std;
int N,Q,K,t1,t2,i,_MAXL;
int mem[500005][2],val[500005],sum,ans[500005];
int main(){
    scanf("%d%d%d",&N,&K,&Q);
    for(i = 1 ; i <= N ; i++){
        scanf("%d%d",&t1,&t2);
        _MAXL = max(_MAXL,t2+1);
        mem[t1][0] = t2+1;
        mem[t1][1] = i;
    }
    for(i = 1 ; i <= _MAXL ; i++){
        sum += val[i];
        if(sum < K && mem[i][0]){
            sum += 1;
            val[mem[i][0]] -= 1;
            ans[mem[i][1]] = true;
        }
    }
    for(i = 1 ; i <= Q ; i++){
        scanf("%d",&t1);
        if(ans[t1]) printf("Y ");
        else printf("N ");
    }
}