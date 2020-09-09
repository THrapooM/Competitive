#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[10005],maxx=-1e9,sum;
int main(){
    while(cin >> n){
        if(!n) return 0;
        sum = 0,maxx  = -1e9;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            sum += a[i];
            if(sum < 0) sum = 0;
            maxx = max(maxx,sum);
        }
        if(maxx!=0)
        printf("The maximum winning streak is %d.\n",maxx);
        else printf("Losing streak.\n");
    }
}