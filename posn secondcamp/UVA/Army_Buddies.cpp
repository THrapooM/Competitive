//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3778
#include<bits/stdc++.h>
using namespace std;
int n,m,L[100005],R[100005],i,l,r;
int main(){
    while(cin >> n >> m){
        if(!n&&!m) return 0;
        for(i=1;i<=n;i++){
            L[i] = i-1;
            R[i] = i+1;
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&l,&r);
            if(L[l]<1) printf("* ");
            else printf("%d ",L[l]);
            if(R[r]>n) printf("*\n");
            else printf("%d\n",R[r]);
            L[R[r]] = L[l];
            R[L[l]] = R[r];
        }
            printf("-\n");
    }
}