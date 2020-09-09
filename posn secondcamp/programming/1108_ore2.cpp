#include<bits/stdc++.h>
using namespace std;
int N,K,i;
long long arr[1000005];
long long maxx = -1e9;
bool visited[1000005];
struct axis{
    long long x,val,now;
    bool operator < (axis k ) const{
        if(k.val!=val) return k.val > val;
        return k.now > now;
    }
}t;
priority_queue<axis>heap;
int main(){
    scanf("%d%d",&N,&K);o
    for(i = 1 ; i <= N ; i++){
        scanf("%lld",&arr[i]);
    }
    heap.push({0,0,0});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
       // printf("t.x = %lld t.val = %lld t.now = %lld\n",t.x,t.val,t.now);
        if(t.x==N+1) {maxx = max(maxx,t.val);}
        if(t.x!=N+1){
            if(arr[t.x+1]+t.now<=K) heap.push({t.x+1,t.val+arr[t.x+1],arr[t.x+1]+t.now});
            else heap.push({t.x+1,t.val,0});
        }
    }
    printf("%d",maxx);
}