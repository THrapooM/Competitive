#include<bits/stdc++.h>
using namespace std;
int a[15],b[15],N,k,t1;
int c = 0;
void food(int x,int y){
    if(x==N+1){
        for(int i=1;i<=N;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        return;
    }
    for(int j=1;j<=N;j++){
        if(x==1&&y!=j) continue;
        if (1 << j & c) continue;
        c |= 1<<j;
        b[x] = j;
        food(x+1,y);
        c ^= 1<<j;
    }
}
int main(){

    int i;
    scanf("%d%d",&N,&k);
    for(i=1;i<=k;i++){
        scanf("%d",&t1);
        a[t1]++;
    }   
    for (int i=1;i<=N;i++){
        if (!a[i]) food(1,i);
    }
}