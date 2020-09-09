#include<bits/stdc++.h>
using namespace std;
int V,E,i,h[3005],rnk[3005],t1,t2,t3,t4,tmp1,tmp2,N,j;
long long money;
bool found;
struct axis{
    int x,y,val;
    bool operator < (axis k) const {
        return k.val < val;
    }
}t;
struct axis2{
    int dis,val;
    bool operator < (axis2 k) const{
        return k.val > val;
    }
}a[300005];
vector<int>vec;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
priority_queue<axis>heap;
int main(){
    scanf("%d%d",&V,&E);
    for(i = 0 ; i < V ; i++) h[i] = i,rnk[i] = 1;
    for(i = 1; i <=E ; i++){
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        if(t4==1) h[head(t1)] = head(t2);
        else heap.push({t1,t2,t3});
    }
    while(!heap.empty()){
            t= heap.top(); heap.pop();
            tmp1 = head(t.x),tmp2 = head(t.y);
            if(tmp1==tmp2) continue;
            if(rnk[tmp1] < rnk[tmp2]){
                rnk[tmp2] += rnk[tmp1];
                h[tmp1] = tmp2;
            }
            else {
                rnk[tmp1] += rnk[tmp2];
                h[tmp2] = tmp1;
            }
            vec.push_back(t.val);
    }
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d%d",&a[i].dis,&a[i].val);
    }
    sort(a+1,a+N+1);
    for(i = 0 ; i < vec.size() ; i++){
        for(j = 1 ; j <= N ; j++){
            if(vec[i]<=a[j].dis) money += a[j].val,found = true;
            if(found) break;
        }
        found = false;
    }
    printf("%lld",money);
}