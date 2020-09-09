//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=977
#include<bits/stdc++.h>
using namespace std;
int N,i,j,k,n,t1;
unordered_map<int,int>a;
bool mem[10005][105];
bool c,visit[10005][105];
bool  divis(int pos,int val){
    if (pos == n && val == 0) return true;
    if (pos == n && val) return false;
    if (visit[pos][val]) return mem[pos][val];
    visit[pos][val]=true;
    return mem[pos][val] = (divis(pos+1,(val+a[pos])%k)|(divis(pos+1,(val-a[pos]+k)%k)));
}
int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
       // memset(mem,0,sizeof(mem));
        memset(visit,0,sizeof(visit));
        scanf("%d%d",&n,&k);
        for(j=0;j<n;j++) {
            scanf("%d",&t1);
            a[j] = abs(t1)%k;
        }
        if(divis(0,0))
        printf("Divisible\n");
        else printf("Not divisible\n");
        a.clear();

    }
    
}