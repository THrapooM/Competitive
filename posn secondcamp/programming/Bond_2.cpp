#include<bits/stdc++.h>
using namespace std;
int n,i,j;
double table[25][25],mem[1<<20];
double bond(int row,int che){
    if(row==n+1) return 1;
    if(mem[che]) return mem[che];
    //  printf("%d %d\n",row,che);
    for(int i = 1; i <= n ; i++){
        if(((1<<(i-1))&che)==0){
            mem[che] = max(mem[che],bond(row+1,che|(1<<(i-1)))*table[row][i]);
        }
    }
    return mem[che];
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%lf",&table[i][j]);
            table[i][j] /= 100;
        }
    printf("%lf",bond(1,0)*100);

}