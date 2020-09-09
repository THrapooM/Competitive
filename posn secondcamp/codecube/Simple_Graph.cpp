#include<bits/stdc++.h>
using namespace std;
int n,i,j,t,k;
int a[100005],cnt;
bool c,z;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        memset(a,0,sizeof(a));
        for(i=1;i<=k;i++){
            scanf("%d",&a[i]);
            if(a[i]!=1) z = 1;
            t += a[i];
        }
        sort(a+1,a+k+1,cmp);
       // for(i=1;i<=k;i++) printf("%d ",a[i]);
        if(t%2==1) {printf("N0\n");}
        else printf("YES\n");
        t = 0;
    //     for(i=1;i<k;i++){
    //        // if(!a[i]&&) {c = 1; break;}
    //          for(j=i+1;j<=k;j++){
    //             if(a[i]&&a[j]) {a[i]--;
    //             a[j]--;
    //             }
    //         }
    //     }
 
    //  if(c||a[k]||z==0){printf("NO\n");}
    //  else if(!a[k]&&!c) {printf("YES\n");}
    //  t = 0;
    //  c= 0;
    //  z = 0;
    //  }
    }
}