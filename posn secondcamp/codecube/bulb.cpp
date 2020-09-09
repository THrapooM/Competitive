//https://www.codecube.in.th/task/27
#include<bits/stdc++.h>
using namespace std;
int N,i,t1;
queue<int>q;
int mem[1024*1024],c,t,x;
int main(){
 ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(i=0;i<N;i++){
        cin >> t1;
        c |= t1 << i;
    }
    if(c==0) {printf("0"); return 0;}
    q.push(0);
   while(!q.empty()){
        t = q.front(); q.pop();
        for(i=0;i<N;i++){
            x = t;
            if(i>0)x ^= 1 << i-1;
            if(i<N-1)x ^= 1 << i+1;
             x ^= 1 << i;
            if(!mem[x]) {mem[x] = mem[t]+1; q.push(x);}
            if(x==c) {printf("%d",mem[x]); return 0;}
        }
   }
   printf("-1");


}
