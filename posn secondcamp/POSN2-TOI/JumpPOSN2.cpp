#include<bits/stdc++.h>
using namespace std;
int t1,n,k,i,a[60005],t2,b[60005],cnt;
int maxx,maxxx;
int main(){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&t1);
        b[i] = t1;
        maxx = max(maxx,t1);
        a[t1]--;
        t2 = t1-k;
        if(t2<0) t2 = 0;
        a[t2]++;

    }
    t1 = 0;
    for(i=0;i<=maxx;i++){
        t1 += a[i];
        if(i==b[cnt]) maxxx = max(maxxx,t1),cnt++;
    }
        cout << maxxx;
    // printf("\n\n");
    // for(i=0;i<=maxx;i++) printf("%d = %d\n",i,a[i]);
   // cout << maxx;
}