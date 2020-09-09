#include<bits/stdc++.h>
using namespace std;
int N,i,j,z,k,ans,t1;
int mem[2][30005];
int val[1005];
int wei[1005];
bool flag;
int main(){
    scanf("%d",&N);
        while(N--){
                scanf("%d",&k);
              for(i=0;i<k;i++)   scanf("%d%d",&val[i],&wei[i]);
              for(i=0;i<k;i++){
                  for(j=1;j<=30;j++){
                      mem[flag][j] = mem[!flag][j];
                      if(j>=wei[i]) mem[flag][j] = max(mem[!flag][j],mem[!flag][j-wei[i]]+val[i]);
                  }
                  flag = !flag;
              }
              scanf("%d",&z);
              for(i=0;i<z;i++){
                  scanf("%d",&t1);
                  ans += mem[!flag][t1];
              }
              cout << ans;
              memset(val,0,sizeof(val));
              memset(wei,0,sizeof(wei));
              memset(mem,0,sizeof(mem));
              flag = false;
              ans = 0;
        }
}