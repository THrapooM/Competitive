#include<bits/stdc++.h>
using namespace std;
int mem[10005][105];
int i,N,x,y,a[10005],t1,j;
int main(){
    scanf("%d",&N);
    while(N--){
    mem[0][0] = 1;
        scanf("%d%d",&x,&y);
        for(i=0;i<x;i++){
            scanf("%d",&t1);
            a[i] = abs(t1)%y;
        }
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
            if(mem[i][j]) mem[i+1][(j+a[i])%y] =mem[i+1][(j-a[i]+y)%y] = true;
            } 
       }
            (mem[x][0])?printf("Divisible\n"):printf("Not divisible\n");
       memset(mem,0,sizeof(mem));
       memset(a,0,sizeof(a));


    }
}