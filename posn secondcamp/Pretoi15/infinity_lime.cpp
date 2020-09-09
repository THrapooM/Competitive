#include<bits/stdc++.h>
using namespace std;
int N,M,i,arr[700005],idx,l,r,mid,qs[700005],t1;
int main(){
    scanf("%d%d",&N,&M);
    for(i = 1 ; i <= N ; i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+N+1);
    for(i = 1 ; i <= N ; i++){
        qs[i] = qs[i-1] + arr[i] - arr[i-1] - 1;
    }
    for(i = 1 ; i <= M ; i++){
        scanf("%d",&t1);
        l = 1,r = N;
        while(l <= r){
			mid = (l+r) >> 1;
            if(qs[mid]>=t1) r = mid-1;
            else l = mid+1;            
		}
        printf("%d ",t1+l-1);
    }
}