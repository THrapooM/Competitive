//https://codeforces.com/contest/505/problem/C
#include<bits/stdc++.h>
using namespace std;
int N,X,t1,_MAXH;
int gem[30005],i,mem[30005][510],visited[30005][510];
int solve(int now,int prev){
    if(now > _MAXH) return 0;
    if(mem[now][prev]) return mem[now][prev];
    if(visited[now][prev-X+250]) return mem[now][prev-X+250];
    visited[now][prev-X+250] = true;
    int tmp = prev;
    int result;
    if(tmp==1){
        result = gem[now] + max(solve(now+tmp+1,tmp+1),solve(now+tmp,tmp));
    }
    else{
        result = gem[now] + max(max(solve(now+tmp-1,tmp-1),solve(now+tmp,tmp)),solve(now+tmp+1,tmp+1));
    }
    mem[now][prev] = result;
    //printf("mem[%d][%d] = %d\n",now,prev,mem[now][prev]);
    return mem[now][prev];

}
int main(){
    scanf("%d%d",&N,&X);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&t1);
        gem[t1]++;
        _MAXH = max(_MAXH,t1);
    }
   printf("%d",solve(X,X));

}