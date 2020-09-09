//https://www.codecube.in.th/task/30
#include<bits/stdc++.h>
using namespace std;
int n,k,mem[505][505][55],a[505][505],i,j;
int emine(int x,int y,int go){
    if(x==n+1||y==n+1) return 0;
    if(mem[x][y][go]) return mem[x][y][go];
    mem[x][y][go] = max(mem[x][y][go],emine(x,y+1,0));
    mem[x][y][go] = max(mem[x][y][go],emine(x+1,y,0));
    if(go<k) mem[x][y][go] = max(mem[x][y][go],max(emine(x+1,y,go+1),emine(x,y+1,go+1))+a[x][y]);
    return mem[x][y][go];
}
int main(){
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    cout << emine(1,0,0);

}
