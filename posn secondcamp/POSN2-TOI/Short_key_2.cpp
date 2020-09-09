#include<bits/stdc++.h>
using namespace std;
int i,t1,t2,j,maxx=-1e9,n,m,k;
vector<int>from[200005];
int mem[200005];
int main(){
    fill(&mem[0],&mem[200004],1e9);
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
    }
    mem[0] = 0;
    for(i=0;i<n;i++){
        if(mem[i]==k) maxx = max(maxx,i);
        for(j=0;j<from[i].size();j++){
            mem[from[i][j]] = min(mem[from[i][j]],mem[i]+1);
        }
        mem[i+1] = min(mem[i+1],mem[i]+1);
    }
    printf("%d\n",mem[n]);
    if(mem[n]<=k) printf("1");
    else printf("0 %d",maxx);


}