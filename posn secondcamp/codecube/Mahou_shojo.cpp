//https://www.codecube.in.th/task/130
#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[100005],mem[100005],temp;
struct axis{
    int x,val;
    bool operator < (axis k) const {
        return k.val < val;
    }
};
priority_queue<axis>heap;
int main(){
    scanf("%d%d",&n,&k);
    for(i = 1;i <= n ; i++) 
        scanf("%d",&a[i]);
        heap.push({1,a[1]});
    for(i = 2; i <= n ; i++){
        if(heap.top().x < i - k) heap.pop();
        mem[i] = a[i] + heap.top().val;
         heap.push({i,a[i]});
    }
    for(i=1;i<=n;i++) printf("%d ",mem[i]);
}