#include<bits/stdc++.h>
using namespace std;
int N,M,K,L,i,j,t1,l,r,all;
int arr[1000005];
int bsearch(int val){
    int ll = 0;
    int rr = N-1;
    int mid,ans = -1;
    while(ll <= rr){
        mid = (ll+rr) >> 1;
          //printf("ll = %d rr = %d mid = %d val = %d\n",ll,rr,mid,val);
        if(arr[mid] > val) rr = mid-1;
        else ll = mid+1;
    }
    //printf("l = %d r = %d mid = %d val = %d\n",ll,rr,mid,val);
    return rr;
}
int main(){
    scanf("%d%d%d%d",&N,&M,&K,&L);
    for(i = 0 ; i < N ; i++) scanf("%d",&arr[i]);
    for(i = 1 ; i <= K ; i++){
        all = 0,r = 0;
        for(j = 1 ; j <=  M ; j++){
            scanf("%d",&t1);
            l = max(r,t1-L-1);
            r = t1+L;
            all += bsearch(r) - bsearch(l);
        }
        printf("%d\n",all);
    }
}