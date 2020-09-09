#include<bits/stdc++.h>
using namespace std;
int N,i;
int l[1000005],r[1000005],a[1000005];
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&a[i]);
        for(i=1;i<=N;i++){
            l[i] = max(l[i-1],a[i-1]);
            r[N-i+1] = max(r[N-i+2],a[N-i+2]);
        }
        // for(i=1;i<=N;i++)
        // printf("r[%d] = %d l[%d] = %d\n",i,r[i],i,l[i]);
         for(i=1;i<N;i++)
         printf("%d ",min(r[i],l[i+1]));
}