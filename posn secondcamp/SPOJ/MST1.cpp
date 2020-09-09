#include<bits/stdc++.h>
using namespace std;
int dp[20000005];
int MST(int x){
    if(x==1) return 0;
    if(dp[x]) return dp[x];
     else if(x%2==0&&x%3!=0) {return dp[x] = 1+min(MST(x-1),MST(x/2));}
     else if(x%3==0&&x%2!=0) {return dp[x]=  1+min(MST(x-1),MST(x/3));}
     else if(x%3==0&&x%2==0){return dp[x]=1+min(MST(x-1),min(MST(x/2),MST(x/3)));}
     else return dp[x] = 1+MST(x-1);
    }
int main(){
        int n,i,num;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            printf("CASE %d:%d\n",i,MST(num));
        }
}
