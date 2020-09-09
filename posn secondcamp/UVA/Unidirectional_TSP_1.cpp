//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=52
#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[15][105],m,ans=1e9;
int mem[15][105],track[15][105],t,x;
// void check(){
//     printf("\nmem\n\n");
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             printf("%d ",mem[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }
// void check1(){
//     printf("\nTrack\n\n");
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             printf("%d ",track[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }
int TSP(int pos,int now){
        if(now==m) return 0;
        if(mem[pos][now]) return mem[pos][now];
        mem[pos][now]  = 1e9;
        int c = 0,to;
        for(int i=0;i<3;i++){
            to = (pos+i+n-1)%n;
           // mem[pos][now] = min(mem[pos][now],TSP((pos+i+n-1)%n,now+1)+a[pos][now]);
            c = TSP(to,now+1)+a[pos][now];
            if(mem[pos][now]>c){
                     mem[pos][now] = c;
                    track[pos][now] = to;
            }
            else if(mem[pos][now]==c && track[pos][now] > to){
                track[pos][now] = to;
            }
        }
        return mem[pos][now];
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        ans = 1e9;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                mem[i][j] = track[i][j] = 0;
                scanf("%d",&a[i][j]);
        }
    } 
    for(i=0;i<n;i++){
        if(ans >TSP(i,0)){
            ans = TSP(i,0);
            t = i;
        }
    }
    // check();
    // check1();
    printf("%d",t+1);
    for(i=0;i<m-1;i++){
        printf(" %d",track[t][i]+1);
        t = track[t][i];
    }
    printf("\n");
    printf("%d",ans);
    printf("\n");
}
}