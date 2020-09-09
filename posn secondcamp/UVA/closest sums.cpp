//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1428
#include<bits/stdc++.h>
using namespace std;
int mx = 0;
int a[1005];
int i,n,j,m,t1,mid,k=0,a2[500000],l,r,con=0;
int main(){
    while(cin >> n){
        if(!n) return 0;
        printf("Case %d:\n",++con);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int cnt = 0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                a2[cnt++] = a[i]+a[j];
        sort(a2,a2+cnt);
        scanf("%d",&m);
        int ans = 1;
        for(i=1;i<=m;i++){
            scanf("%d",&t1);
            while(abs(t1-a2[ans-1])>=abs(t1-a2[ans])&&ans<cnt) ans++;
            printf("Closest sum to %d is %d.\n",t1,a2[ans-1]);
            ans = 1;
        }
        memset(a,0,sizeof(a));
        memset(a2,0,sizeof(a2));
        }
}
