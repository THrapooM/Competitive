#include<bits/stdc++.h>
using namespace std;
int N,d,t1,t2,t3,n,a[1030][1030],maxy=-1e9,maxx=-1e9,i,j,check,val,xx,xy;
int main(){
    scanf("%d",&N);
    while(N--){
        maxx = maxy = val = -1;
        fill(&a[0][0],&a[1025][1025],0);
        scanf("%d",&d);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d%d",&t1,&t2,&t3);
            for (int j = t1-d; j <= t1+d; j++){
                for (int k = t2-d; k <= t2+d; k++){
                    if (j >= 0 && k >= 0 && j <= 1024 && k <= 1024)
                        a[j][k] += t3;
                }
            }

        }
        for(i=0;i<=1024;i++){
            for(j=0;j<=1024;j++){
                if(val<a[i][j]){
                    val = a[i][j];
                    xx  = i;
                    xy = j;
                }
            }
        }
        printf("%d %d %d\n",xx,xy,val);
           
    }
}