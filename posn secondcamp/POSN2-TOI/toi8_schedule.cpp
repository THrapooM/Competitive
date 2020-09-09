#include<bits/stdc++.h>
using namespace std;
int timee,N,i,tx,tval;
int a[1005],b[1005];
bool visited[1005][1005];
struct axis{
    int idxa,idxb,day,val;
    bool operator < (axis k) const {
        if(k.day!=day) return k.day < day;
        return k.val < val;
    }
}t;
priority_queue<axis>heap;
int main(){
    scanf("%d%d",&timee,&N);
   // fill(&mem[0][0],&mem[1004][1004],1e9);
    for(i = 1 ; i <= N ; i++)
    scanf("%d",&a[i]);
    for(i = 1 ; i <= N ; i++)
    scanf("%d",&b[i]);
    heap.push({0,0,1,0});
    while(!heap.empty()){
        t = heap.top(); heap.pop();
        //printf("t.idxa = %d t.idxb = %d day = %d val = %d\n",t.idxa,t.idxb,t.day,t.val);
        if(visited[t.idxa][t.idxb]) continue;
        visited[t.idxa][t.idxb] = true;
        if(t.idxa==N && t.idxb==N){
            printf("%d\n",t.day);
            printf("%d",t.val);
            return 0;
        }
        if(t.idxa!=N){
            tx = t.idxa+1;
            tval = t.val + a[tx];
            if(tval <= timee) heap.push({tx,t.idxb,t.day,tval});
            else if(tval > timee) heap.push({t.idxa+1,t.idxb,t.day+1,a[tx]});
        }
        if(t.idxb!=N){
            tx = t.idxb+1;
            tval = t.val + b[tx];
            if(tval <= timee) heap.push({t.idxa,tx,t.day,tval});
            else if(tval > timee) heap.push({t.idxa,t.idxb+1,t.day+1,b[tx]});
        }
    }
}
