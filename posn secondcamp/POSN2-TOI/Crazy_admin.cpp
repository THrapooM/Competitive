//https://www.proprog.tk/tasks/toi10_crazyadmin/descs/6777
#include<bits/stdc++.h>
using namespace std;
int a[105],mem[105][25],n,k;
int crazy(int pos,int cwire){
    if(pos==k&&cwire<=n) return 0;
    if(cwire>n) return 1e9;
    if(mem[pos][cwire]) return mem[pos][cwire];
    mem[pos][cwire] = 1e9;
    int sum = 0;
    for(int i=pos;i<k;i++){
        sum += a[i];
        mem[pos][cwire] = min(mem[pos][cwire],max(sum,crazy(i+1,cwire+1)));
    }
    return mem[pos][cwire];
}
int main(){
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
    cout << crazy(0,0);
        
}