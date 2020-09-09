//https://codeforces.com/problemset/problem/474/D
#include<bits/stdc++.h>
using namespace std;
int t1[100005],t2[100005],maxx=-1e9,N,i,k;
const int inf = 1e9+7;
int mem[100005];
int main(){
    scanf("%d%d",&N,&k);
    for(i=1;i<=N;i++){
        scanf("%d%d",&t1[i],&t2[i]);
        maxx = max(maxx,t2[i]);
    }
    mem[0] = 1;
    for(i=1;i<=maxx;i++){
        mem[i] += (mem[i-1]);
        if (i >= k) mem[i] += (mem[i-k]);
        mem[i] %= inf;
    }
    //mem[0] = 0;
    for(i=1;i<=maxx;i++){
       mem[i] = (mem[i]+mem[i-1])%inf;
       //printf("%d ",mem[i]);
    }
    for(i=1;i<=N;i++){
        printf("%d\n",(mem[t2[i]]-mem[t1[i]-1]+inf)%inf);
    }
}