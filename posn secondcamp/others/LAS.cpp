#include<bits/stdc++.h>
using namespace std;
int N,Q,a[1005],mem[1005][1005][2];
int LAS(int now,int prev,int state){
        if(now > N) return 0;
        if(mem[now][prev][state]) return mem[now][prev][state];
        if(state==1 && a[now] < a[prev]){
            mem[now][prev][state] = max(mem[now][prev][state],LAS(now,now,0)+1);
        }
        else if(state==0 && a[now] > a[prev]){
            mem[now][prev][state] = max(mem[now][prev][state],LAS(now,now,1)+1);
        }
        mem[now][prev][state] = max(mem[now][prev][state],LAS(now+1,prev,state));
        return mem[now][prev][state];
}
int main(){
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&N);
        a[0] = 1e9;
        a[N+1] = -1e9;
        memset(mem,0,sizeof(mem));
        for(int i = 1 ; i <= N ; i++){
            scanf("%d",&a[i]);
        }
    printf("%d\n",max(LAS(1,0,1),LAS(1,N+1,0)));
    }
}