#include<bits/stdc++.h>
using namespace std;
int a[1005],t1,n,k,mem[1005][305];
int qsum(int x,int y){
    return a[y]-a[x-1];
}
int parti(int x,int y){
    //cout << x << " " << y<<endl;
    if(x==n+1 && y==k+1) return 0;
    if(y > k+1) return 1e9;
    if(mem[x][y]) return mem[x][y];
    mem[x][y] = 1e9;
    for(int i=x;i<=n;i++){
        mem[x][y] = min(mem[x][y],max(qsum(x,i),parti(i+1,y+1)));
        printf("mem[%d][%d] = %d | qsum %d %d\n",qsum(x,i),parti(i+1,y+1));
    }
    return mem[x][y];
}
int main(){
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
            scanf("%d",&t1);
            a[i]  = t1+a[i-1];
    }
    cout << parti(1,1);
}
