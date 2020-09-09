//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1428
#include<bits/stdc++.h>
using namespace std;
int n,i,t1,m,j;
int sum[500505];
int a[1005];
int num,l,r,mid;
int bs(){
    int mid,l=0,r=num,minn;
    while(l<r){
        mid = l+r >> 1;
        if(sum[mid]==t1){return sum[mid];}
        else if(a[mid]>t1) r = mid-1;
        else l = mid+1;
    }
    minn = sum[l];
    if(l+1<=num){
        if(abs(sum[l+1]-t1)<abs(minn-t1)) minn = sum[l+1];
    }
    if(l-1>=0)

}
int main(){
    while(cin >> n){
        if(!n) return 0;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                sum[num++] = a[i]+a[j];
            }
        }
            sort(sum,sum+num);
            scanf("%d",&m);
            for(i=0;i<m;i++){
                scanf("%d",&t1);
                bs();
            }
        }
}
