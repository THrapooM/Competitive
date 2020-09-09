#include<bits/stdc++.h>
using namespace std;
int mem[260][260],N,i;
string s;
int segi(int x,int y){
    if(mem[x][y]) return mem[x][y];
    for(int i=x;i<y;i++){
           int l = segi(x,i);
           int  r = segi(i+1,y);
            if (mem[x][y] == 7) return mem[x][y];
            if(l&1<<0){
                if(r&1<<0) mem[x][y] |= 1<<2;
                if(r&1<<1) mem[x][y] |= 1<<1;
                if(r&1<<2) mem[x][y] |= 1<<0;
            }
            if(l&1<<1){
                if(r&1<<0) mem[x][y] |= 1<<2;
                if(r&1<<1) mem[x][y] |= 1<<1;
                if(r&1<<2) mem[x][y] |= 1<<1;
            }
            if(l&1<<2){
                if(r&1<<0) mem[x][y] |= 1<<1;
                if(r&1<<1) mem[x][y] |= 1<<2;
                if(r&1<<2) mem[x][y] |= 1<<1;
            }
    }
    return mem[x][y];
}
int main(){
    int T = 20;
    while(T--){
        scanf("%d",&N);
        cin >> s;
        for(i=0;i<N;i++){
            if(s[i]=='0') mem[i][i] = 1;
            else if(s[i]=='1') mem[i][i] = 1<<1;
            else mem[i][i] = 1<<2;
        }
        if(1&segi(0,N-1)) printf("yes\n");
        else printf("no\n");
        memset(mem,0,sizeof(mem));

    }
}