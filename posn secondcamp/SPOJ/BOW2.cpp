//https://www.spoj.com/problems/BORW/
#include<bits/stdc++.h>
using namespace std;
int mem[205][205][205],N,i,j,n[205];
int borw(int x,int lis,int lds){
    if(x==N) return 0;
    if(mem[x][lis][lds]) return mem[x][lis][lds];
    if(n[x]>n[lis]) mem[x][lis][lds] = max(mem[x][lis][lds],borw(x+1,x,lds)+1);
    if(n[x]<n[lds]) mem[x][lis][lds] = max(mem[x][lis][lds],borw(x+1,lis,x)+1);
    return mem[x][lis][lds] = max(mem[x][lis][lds],borw(x+1,lis,lds));
}
int main(){
        while(cin >> N){
            if(N==-1) return 0;
            n[203] = -1e9;
            n[204] = 1e9;
            for(i=0;i<N;i++){
                scanf("%d",&n[i]);
            }
            cout << N-borw(0,203,204)<<endl;
            memset(mem,0,sizeof(mem));

        }
}
