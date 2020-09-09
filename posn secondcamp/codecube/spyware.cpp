#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<int>from[100005];
int maxx = -1e9;
priority_queue<int>heap;
bool visited[100005],c;
long long cnt;
int mem[100005],n,m,k,i,val[100005],t1,t2,t;
vector<int>wei[100005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&val[i]);
    }
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
    }
    q.push(k);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(visited[t])
            continue;
        visited[t] = true;
        for(i=0; i<from[t].size(); i++)
        {
            int tx = from[t][i];
            if(!visited[tx] && !mem[tx])
            {
                mem[tx] = mem[t]+1;
                maxx = max(maxx,mem[tx]);
                wei[mem[tx]].push_back(val[tx]);
                q.push(tx);
            }
        }
    }

    for(i=maxx; i>=1; i--)
    {
        for (auto c:wei[i])
            heap.push(c);
        if(heap.top()<0)
            continue;
        cnt+= heap.top();
        heap.pop();
    }
    for(i=1; i<=n; i++)
    {
        if(!visited[i]&&val[i]>=0)
            cnt+= val[i];
    }
    printf("%lld",cnt);



}
