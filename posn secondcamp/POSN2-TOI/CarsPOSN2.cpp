#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[105][45],i,j,x,track[105][45];
bool c[105][45];
stack<int>st;
void check(int a[][45]){
    for (int i = 1 ; i <= k; i++){
        for (int j = 1; j <= n; j++) printf("%d ",track[i][j]);
        cout << endl;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    c[0][m] = true;
    for(i=0;i<=k;i++){
        for(j=1;j<=n;j++){
            if(c[i][j]){
              if(!a[i+1][j]){
                  c[i+1][j] = true;
                   track[i+1][j] = 3;
              }
               if(!a[i+1][j-1]){
                  c[i+1][j-1] = true;
                  track[i+1][j-1] = 1;
              }
              if(!a[i+1][j+1]){
                  c[i+1][j+1] = true;
                   track[i+1][j+1] = 2;
              }
            }
        }
    }
    // check(track);
    // return 0;
    for(i=1;i<=n;i++) if(track[k][i]) x = i;
    for(i=k;i>=1;i--){
        st.push(track[i][x]);
        if(track[i][x]==1) x = x+1;
        else if(track[i][x]==3) x=x;
        else if(track[i][x]==2) x= x-1;
    }
    while(!st.empty()){
        printf("%d\n",st.top());
        st.pop();
    }

   

}