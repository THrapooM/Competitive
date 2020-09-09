#include<bits/stdc++.h>
using namespace std;
int N,i,j,area[20][20],cnt,x;
bool column[20],axis1[20],axis2[20];
char t1;
void nquen(int y){
    if(y==N+1) {cnt++; return;}
    for(int i=1;i<=N;i++){
        if(column[i] || axis1[i+y-1] || axis2[i-y+N]||area[y][i]=='*') continue;
        column[i] = axis1[i+y-1] = axis2[i-y+N] = 1;
        nquen(y+1);
        column[i] = axis1[i+y-1] = axis2[i-y+N] = 0;
    } 
}
int main(){ 
    while(1){
        scanf("%d",&N);
        if(!N) return 0;
       
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            scanf(" %c",&area[i][j]);
        }
    }
     nquen(1);
    cout << cnt;
    
}
}