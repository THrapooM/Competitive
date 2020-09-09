#include<bits/stdc++.h>
using namespace std;
int t1,t2,minn=1e9,minnn=1e9,maxxx=-1e9,maxx=-1e9,mi,mx;
vector<int>from[2005];
queue<int>q;
int mem[2005];
bool visit[2005];
int V,E,i;
int main(){
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
        minn = min(t1,minn);
        minnn = min(t2,minn);
        maxx = max(t1,maxx);
        maxxx = max(t2,maxxx);
    }
    mi = min(minn,minnn);
    mx = max(maxx,maxxx);
    //cout << mx;
    for(i=mi;i<=mx;i++){
        sort(from[i].begin(),from[i].end());
    }
    mem[mi] = 1;
    q.push(mi);
    while(!q.empty()){
        int t = q.front(); q.pop();
        if(visit[t]) continue; visit[t]= true;
        for(i=0;i<from[t].size();i++){
                int tx = from[t][i];
                //if(visit[from[t][i]]) continue;
                if(mem[tx]!=mem[t]&&mem[tx]&&mem[t])continue;
               if(mem[tx]==mem[t]&&visit[tx])
                { 
                mem[t] = mem[tx]+1;
                }
                else if(mem[tx]==mem[tx]&&!visit[tx]){
                    mem[tx] = mem[t]+1;
                }
                else if(!mem[tx]) mem[tx] = 1;
                else if(!mem[tx]&&tx>t) mem[tx] = mem[t]+1;
                 q.push(tx);
              //  if(tx==35) cout << 1;
              printf("mem[%d] = %d mem[%d] = %d\n",t,mem[t],tx,mem[tx]);
        }
    }
    for(i=mi;i<=mx;i++){
        if(mem[i]) printf("mem[%d] = %d\n",i,mem[i]);
    } 
}