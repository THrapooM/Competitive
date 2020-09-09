#include<bits/stdc++.h>
using namespace std;
int a[605],i,N,x;
int mem[605][605];
int qsum(int x,int y){
        return a[y]-a[x-1];
}
int apoint(int x,int y){
        if(mem[x][y]) return mem[x][y];
        if (x == y) return 0;
        for(int i=x;i<y;i++){
            if(qsum(x,i) < qsum(i+1,y))
                mem[x][y] = max(mem[x][y],2*qsum(x,i)+qsum(i+1,y)+apoint(x,i)+apoint(i+1,y));
            else mem[x][y] = max(mem[x][y],qsum(x,i)+2*qsum(i+1,y)+apoint(x,i)+apoint(i+1,y));
        }
        return mem[x][y];
}
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&x);
        a[i] = a[i-1]+x;
    }
    cout <<apoint(1,N);
}
