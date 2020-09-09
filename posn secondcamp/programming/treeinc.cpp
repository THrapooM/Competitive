//https://programming.in.th/task/rev2_problem.php?pid=1091
#include<bits/stdc++.h>
using namespace std;
int n,i,t1,t2,maxx = -1e9;
int mem[300005],head[300005];
vector<int>from[300005];
void dfs(int now,int wei){
    if(mem[now]>=wei) return;
    mem[now] = wei;
   // printf("i = %d now = %d wei = %d\n",i,now,wei);
    for(int i=0;i<from[now].size();i++){
        if(from[now][i]>now) dfs(from[now][i],wei+1);
    }
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
    }
    for(i=1;i<=n;i++) dfs(i,1);
    for(i=1;i<=n;i++) maxx = max(maxx,mem[i]);
    printf("%d",maxx);
}