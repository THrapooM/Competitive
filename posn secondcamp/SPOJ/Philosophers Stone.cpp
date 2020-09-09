//https://www.spoj.com/problems/BYTESM2/
#include<bits/stdc++.h>
using namespace std;
struct axis{
    int pos,val;
    bool operator <(axis k) const{
    return k.val > val;
    }
}t;
//priority_queue<axis>heap;
priority_queue<int>pq;
int n,r,c,i,j,a[105][105];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<r;i++){
                priority_queue<axis>heap;
            for(j=0;j<2;j++){
                heap.push({j,a[i-1][j]});
            }
            for(j=0;j<c;j++){
                if(j+1<c) heap.push({j+1,a[i-1][j+1]});
                while(heap.top().pos<j-1) heap.pop();
                a[i][j] += heap.top().val;
            }
            if (i == r-1) for (j = 0; j < c; j++) pq.push(a[i][j]);
        }
//        for(i=0;i<r;i++){
//            for(j=0;j<c;j++){
//                printf("%2d ",a[i][j]);
//            }printf("\n");
//        }
        printf("%d\n",pq.top());
        //while(!heap.empty()) heap.pop();
        while(!pq.empty()) pq.pop();
        memset(a,0,sizeof(a));
    }

}
