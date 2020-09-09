#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,mem[15][105],ans=1e9,a[15][105],track[15][105],t;
void check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
}
void check1(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",track[i][j]);
        }
        printf("\n");
    }
}
int TSP(int nxt,int col){
        if(col==m) return 0;
        if(mem[nxt][col]) return mem[nxt][col];
        mem[nxt][col] = 1e9;
        int c = 0;
        for(int i=0;i<3;i++){
            int to = (nxt+i+n-1)%5;
            //mem[nxt][col] = min(mem[nxt][col],TSP(to,col+1)+a[nxt][col]);
            c = TSP(to,col+1)+a[nxt][col];
            if(mem[nxt][col]>c){
                mem[nxt][col] = c;
                track[nxt][col] = to;
            }
            else if(mem[nxt][to]==c && track[nxt][col] > to){
                mem[nxt][col] = c;
                track[nxt][col] = to;
            }
        }
        return mem[nxt][col];
}

int main(){
    while(cin >> n >> m){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&a[i][j]);
            }
        }
    for(i=0;i<n;i++){
        if(ans>TSP(i,0)){
        ans = TSP(i,0);
        t = i;
        }
    }   
    // cout  << ans;
     check();
     printf("\n\n");
     check1();
     printf("\n\n");
    printf("%d ",t+1);
    for(i=0;i<m-1;i++){
        printf("%d ",track[t][i]+1);
        t = track[t][i];
    }
   printf("\n%d",ans);
    }
}