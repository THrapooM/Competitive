//POSN2
#include<bits/stdc++.h>
using namespace std;
int maxx = -1e9,i,j,a[1005][1005],n,m,track[1005][1005],t;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++) track[1][i] = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(i%2==0){
                if(a[i-1][j]>a[i-1][j+1]) track[i][j]+=track[i-1][j];
                else if(a[i-1][j]<a[i-1][j+1]) track[i][j]+=track[i-1][j+1];
                else track[i][j] += track[i-1][j+1]+track[i-1][j];
                a[i][j] += max(a[i-1][j],a[i-1][j+1]);
            }
            else if(i%2==1){
                if(a[i-1][j]>a[i-1][j-1]) track[i][j]+=track[i-1][j];
                else if(a[i-1][j]<a[i-1][j-1]) track[i][j]+=track[i-1][j-1];
                else track[i][j] += track[i-1][j]+track[i-1][j-1];
                a[i][j] +=max(a[i-1][j],a[i-1][j-1]);
            } 
            if(i==n) maxx = max(maxx,a[i][j]);
        }
    }
    for(i=1;i<=m;i++){
        if(a[n][i]==maxx) t += track[n][i];
   }
    cout << maxx << " " << t;
    
}