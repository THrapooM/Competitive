#include<bits/stdc++.h>
using namespace std;
int A,B,a[1005],b[1005],i,ans;
int main(){
    scanf("%d%d",&A,&B);
    for(i=0;i<A;i++) scanf("%d",&a[i]);
    sort(a,a+A);
    for(i=0;i<B;i++) scanf("%d",&b[i]);
    sort(b,b+B);
    if(A==1&&B==1){printf("%d",a[0]+b[0]+100); return 0;}
    else{
        if(a[1]&&b[1]){
            ans = min(a[0]+a[1],min(b[0]+b[1],a[0]+b[0]+100));
            printf("%d",ans);

        }
        else if(!a[1]&&b[1]){
            ans = min(a[0]+b[0]+100,b[0]+b[1]);
            printf("%d",ans);
        }
        else{
            ans = min(a[0]+a[1],a[0]+b[0]+100);
            printf("%d",ans);
        }   
    }
}