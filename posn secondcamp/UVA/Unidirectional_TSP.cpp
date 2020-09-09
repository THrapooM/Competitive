//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=52
#include<bits/stdc++.h>
using namespace std;
struct axis{
    int pos,val;
    bool operator <(axis k) const{
        return k.val < val;
    }
}t;
int a[105][15],i,j,k,n,m;
int main(){
    while(cin >> n >> m && n && m){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&a[j][i]);
            }
        }
        // for(i=0;i<m;i++){
        //     for(j=0;j<n;j++){
        //         printf("%d ",a[i][j]);
        //     }printf("\n");
        // }
        for(i=1;i<m;i++){
            priority_queue<axis>heap;
            for(j=0;j<=2;j++){
               int x =(j+n-1)%n;
                heap.push({x,a[i-1][x]});
            }
            for(j=0;j<n;j++){
                int k = (j+n-1)%n;
                if(k+1<n) heap.push({k+1,a[i-1][k+1]});
                while(heap.top().pos<k-1) heap.pop();
                a[i][j] += heap.top().val;

            }
        }

}
        for(i=0;i<m;i++){
            for(j=0;j<n;j++) printf("%d ",a[i][j]);
    
        printf("\n");}
}
