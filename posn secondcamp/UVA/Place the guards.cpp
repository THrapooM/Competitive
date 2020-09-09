//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2021
#include<bits/stdc++.h>
using namespace std;
int N,V,E,i,t1,t2,ans,j;
int guard[205],g[2];
bool  found;
vector<int>from[205];
queue<int>q;
int main(){
        scanf("%d",&N);
        while(N--){
            scanf("%d%d",&V,&E);
            for(i=0;i<E;i++){
                scanf("%d%d",&t1,&t2);
                from[t1].push_back(t2);
                from[t2].push_back(t1);
            }
            fill(&guard[0],&guard[204],-1);
            for(i=0;i<V;i++){
                if(guard[i]==-1){
                    g[0] = 0; g[1] = 1;
                    q.push(i);
                    guard[i] = 1;
                  while(!q.empty()){
                      int t = q.front(); q.pop();
                      int k = guard[t];
                      for(j=0;j<from[t].size();j++){
                          if(guard[from[t][j]]!=-1 && guard[from[t][j]]==k){
                              found = true;
                              break;
                          }
                           if(guard[from[t][j]]!=-1) continue;
                          guard[from[t][j]] = !k;
                          g[!k]++;
                          q.push(from[t][j]);
                      }
                      if(found) break;
                  }
                  if(found) break;
               if(from[i].empty()) ans+=1;
               else ans += min(g[0],g[1]);
                }
            }
            if(found) printf("-1\n");
            else printf("%d\n",ans);
            for(i=0;i<V;i++) from[i].clear();
            while(!q.empty()) q.pop();
            ans = 0;
            found = false;
            }


}
