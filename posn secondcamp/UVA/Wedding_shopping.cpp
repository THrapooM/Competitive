//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445
#include<bits/stdc++.h>
using namespace std;
int n,k,j,i,y,budget,m;
int a[25][205];
int mem[25][205],siz[25];
int wedd(int x,int money){
        if(money<0) return -1e9;
        if(x==y) return budget-money;
        if(mem[x][money]) return mem[x][money];
        for(int i=0;i<siz[x];i++){
            mem[x][money] = max(mem[x][money],wedd(x+1,money-a[x][i]));
        }
        return mem[x][money];

}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&budget,&y);
        for(i=0;i<y;i++){
            scanf("%d",&siz[i]);
            for(j=0;j<siz[i];j++){
                scanf("%d",&a[i][j]);
            }
        }
        m = wedd(0,budget);
        //cout << m;
        memset(mem,0,sizeof(mem));
        if(!m){printf("no solution\n"); continue;}
        printf("%d\n",m);
     
    }
}