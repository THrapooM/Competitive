#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],mem[25][105];
int f(int wire,int x){
    if(x==m&&wire<=n) return 0;
    if(wire>n) return 1e9;
    if(mem[wire][x]) return mem[wire][x];
    mem[wire][x] = 1e9;
    int sum = 0;
    for(int i=x;i<m;i++){
        sum += a[i];
        mem[wire][x] = min(mem[wire][x],max(sum,f(wire+1,i+1)));
    }
    return mem[wire][x];
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++) scanf("%d",&a[i]);
   cout <<  f(0,0);
}