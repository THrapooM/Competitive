//https://www.codecube.in.th/task/176
#include<bits/stdc++.h>
using namespace std;
int V,E,i,j,Q,t1,t2,h[100005],t3,t4;
struct con{
    int x,y;
}t;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
queue<con>heap;
int main(){
    scanf("%d%d%d",&V,&E,&Q);
    for(i=1;i<=E;i++){
        scanf("%d%d",&t1,&t2);
        heap.push({t1,t2});
    }
    for(i=1;i<=V;i++) h[i] = i;
    while(!heap.empty()){
        t = heap.front(); heap.pop();
        if(head(t.x)!=head(t.y)){
            h[head(t.x)] = head(t.y);
            //h[head(t.x)] = head(t.y);
        }
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d",&t3,&t4);
       // printf("h[%d]=%d h[%d]=%d\n",t3,h[t3],t4,h[t4]);
        if(head(t3)!=head(t4)) printf("no\n");
        else printf("yes\n");
    }


}
