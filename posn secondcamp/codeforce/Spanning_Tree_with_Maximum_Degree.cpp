//https://codeforces.com/problemset/problem/1133/F1
#include<bits/stdc++.h>
using namespace std;
int V,E,t1,t2,i,a[200005],maxx=-1e9,pos,cnt;
queue<int>q;
vector<int>from[200005];
bool visited[200005];
int main(){
        scanf("%d%d",&V,&E);
        for(i=0;i<E;i++){
            scanf("%d%d",&t1,&t2);
            a[t1]++;
            a[t2]++;
            from[t1].push_back(t2);
            from[t2].push_back(t1);
        }
        for(i=1;i<=V;i++){
            if(maxx<a[i]) {maxx = a[i]; pos = i;}
        }
        // printf("\n");
        //  printf("%d %d",maxx,pos);
        // printf("\n\n");
        q.push(pos);
        //visited[pos] = true;
        while(!q.empty()){
        int x = q.front(); q.pop();
            visited[x] = true;
            for(i=0;i<from[x].size();i++){
                // q.push({from[x][i]});
                if(!visited[from[x][i]]){ 
                    visited[from[x][i]] = true;
                printf("%d %d\n",x,from[x][i]);
                q.push({from[x][i]});
                }
            }            
        }
}