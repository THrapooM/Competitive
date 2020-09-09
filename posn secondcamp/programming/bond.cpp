#include<bits/stdc++.h>
using namespace std;
int n;
double a[25][25],mem[1<<20],t1;
double bond(int x,int y){
    if(x==n) return 1;
    if (mem[y]) return mem[y];
    for(int i=0;i<n;i++){
        if(!(y & (1 << i))){
            mem[y] = max(mem[y],a[x][i]*bond(x+1,y|(1<<i)));
        }
    }
    return mem[y];
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
            a[i][j] /= 100.0;
        }
    }
    printf("%.6f",bond(0,0)*100);

}
