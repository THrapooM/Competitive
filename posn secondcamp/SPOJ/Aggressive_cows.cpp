#include<bits/stdc++.h>
using namespace std;
int tc,a[100005],i,N,C;
bool u,v;
bool find(int val){
    int temp = a[1],cnt=0;
    for(int i=1;i<=N;i++){
        if(a[i]-temp>=val){
            cnt++,temp = a[i];
            if(cnt==C-1) return true;
        }
    }
    return false;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&N,&C);
        for(i=1;i<=N;i++) scanf("%d",&a[i]);
        sort(a+1,a+N+1);
        //for(i=1;i<=N;i++) printf("a[%d] = %d\n",i,a[i]);
        int l = a[1],r = a[N],mid;
        bool found = false;
        while(l<=r){
            mid = l + r >> 1;
            u = find(mid),v = find(mid+1);
           // printf("mid = %d\n",mid);
            if(u&&!v){
                printf("%d\n",mid);
                found = true;
            }
            else if(u&&v) l = mid+1;
            else r = mid-1;
            if(found) break;
        }
    }
}