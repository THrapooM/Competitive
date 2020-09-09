//https://codeforces.com/problemset/problem/474/D
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
int i,n,k,j,cnt,maxx=-1e9;
int mem[100005];
int t1[100005],t2[100005];
int f(int x){
    if(x==0) return 1;
    if(x<0) return 0;
    if(mem[x]) return mem[x];
    long long con = (f(x-1)+f(x-k))%inf;
    return mem[x]=max(mem[x],(int)con);
}
int main(){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d%d",&t1[i],&t2[i]);
        maxx = max(maxx,t2[i]);
}
//cout << 1;
    f(maxx);
    // for(i=0;i<=maxx;i++){
    //     printf("%d ",mem[i]);
    // }
    for(i=1;i<=maxx;i++){
        mem[i] = (mem[i] +mem[i-1])%inf;
    }
   // printf("\n");
    for(i=0;i<n;i++){
        printf("%d\n",(mem[t2[i]]-mem[t1[i]-1]+inf)%inf);
    }
}
