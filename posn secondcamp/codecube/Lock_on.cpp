#include<bits/stdc++.h>
using namespace std;
int N,k,t1,t2,maxx=-1e9,minn=1e9,i,x = 1e9,temp;
int main(){
    scanf("%d%d",&N,&k);
    for(i=0;i<N;i++){
        scanf("%d%d",&t1,&t2);
        if(t1>t2) swap(t1,t2);
        maxx = max(maxx,t1);
        minn = min(minn,t2);
    }
    if(maxx>minn) {printf("-1"); return 0;}
    for(i=maxx;i<=minn;i++){
        temp = abs(i-k);
        if(x<temp) break;
        x = temp;
    }
    printf("%d",x);
}