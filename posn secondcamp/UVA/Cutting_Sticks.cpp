#include<bits/stdc++.h>
using namespace std;
int len,a[55],mem[55][55],N,i;
int cut(int x,int y){
        if(x+1==y) return 0;
        if(mem[x][y]) return mem[x][y];
        mem[x][y] =  1e9;
        for(int i=x+1;i<y;i++){
            mem[x][y] = min(mem[x][y],cut(x,i)+cut(i,y)+a[y]-a[x]);
        }
        return mem[x][y];
}
int main(){
    while(1){
        scanf("%d",&len);
        if(!len) return 0;
        memset(mem,0,sizeof(mem));
        scanf("%d",&N);
        a[0] = 0; 
        for(i=1;i<=N;i++){
            scanf("%d",&a[i]);
        }
        a[N+1] = len;
        printf("The minimum cutting is %d.\n",cut(0,N+1));
    }
}