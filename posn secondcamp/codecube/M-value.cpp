#include<bits/stdc++.h>
using namespace std;
int tc,N,K,i,a[1005],t1,j,cnt,temp[100011],ans;
int main(){
    scanf("%d",&tc);
    while(tc--){
        cnt++,ans=0;
        memset(temp,-1,sizeof(temp));
        scanf("%d%d",&N,&K);
        for(i=0;i<N;i++){
            scanf("%d",&a[i]);                    
        }
        temp[0] = 0;
        for(i=0;i<N;i++){
            for(j=0;j<K;j++){
                if(temp[j]<=i && temp[j]!=-1 && temp[(j+a[i])%K]==-1) 
                    temp[(j+a[i])%K] = i+1;
            }
        }
        for(i=0;i<K;i++) if(temp[i]>-1) ans = i;
        printf("Case #%d: %d\n",cnt,ans);
    }
}