#include<bits/stdc++.h>
using namespace std;
int mi=-1e9,mx=1e9,a[100005],n;
bool cat(int x){
    int t4 = 0;
    int che = 0;
    for(int i=1;i<=n;i++){
        if(a[i]>x){
            if(t4==0){
                che  = a[i];
            }
           else if(che!=a[i]) return 0;
            t4 = (t4+1)%2;
        }
        }
  return 1;
    }
int main(){
    int  i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mi = min(mi,a[i]);
        mx = max(mx,a[i]);
        }
        while(1){
            int mid = (mi+mx)/2;
            if(cat(mid) && !cat(mid-1)){
                printf("%d",mid); return 0;
            }
            else if(cat(mid) && cat(mid-1)){
                mx = mid-1;
            }
            else mi = mid+1;
        }
}