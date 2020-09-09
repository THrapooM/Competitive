#include<bits/stdc++.h>
using namespace std;
int N,i,a[1005],qs[1005],j,maxx,minn,temp = 1e9,st2,st3;
int main(){
    scanf("%d",&N);
    for(i = 1; i <= N ; i++){
        scanf("%d",&a[i]);
        qs[i] += qs[i-1] + a[i];
    }
    for(i = 1;i < N-1 ; i++){
        for(j = i+1 ; j<N ; j++){
             maxx = max(qs[i],max(qs[j]-qs[i],qs[N]-qs[j]));
             minn = min(qs[i],min(qs[j]-qs[i],qs[N]-qs[j]));
             if(temp >= maxx - minn){
                    st2 = i;
                    st3 = j;
                    temp = maxx - minn;
             }
        }
    }
    printf("%d %d",st2+1,st3+1);
}