//https://www.codecube.in.th/task/130
#include<bits/stdc++.h>
using namespace std;
int i,n,k,a[100005];
int mem[100005];
int mahou(int pos){
    if(pos==n+1) return 0;
    if(mem[pos]) return mem[pos];
    int maxx = 0;
    mem[pos]  = 1e9;
    for(int i = 1; i<= k && pos+i-1 <= n ; i++){
            maxx = max(maxx,a[pos+i-1]);
            mem[pos] = min(mem[pos],maxx+mahou(pos+i));
    }
    return mem[pos];
}
int main(){
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        printf("%d",mahou(1));
}