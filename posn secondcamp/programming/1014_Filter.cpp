#include<bits/stdc++.h>
using namespace std;
int w,h,n,t1,t2,maxx=-1e9,i,a[4005],cnt2,cnt1;
int main(){
    scanf("%d%d%d",&w,&h,&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&t1,&t2);
        t2 = t1 + t2 -1;
        maxx = max(maxx,t2+1);
        a[t1]++;
        a[t2+1]--;
    }
    for(i=0;i<=maxx;i++){
        a[i] += a[i-1];
        //printf("a[%d] = %d\n",i,a[i]);
    }
    for(i=0;i<w;i++){
        if(a[i]==0) cnt2++;
        else if(a[i]==1) cnt1++;
    }
    printf("%d %d",h*cnt2,h*cnt1);
}