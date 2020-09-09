#include<bits/stdc++.h>
using namespace std;
struct node
{
    int st,fi,val;
    bool operator <(node t) const
    {
        return t.val < val;
    }
};
int t1,t2,t3,i,j,h[200005];
priority_queue<int>pq;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        pq.push({t1,t2,t3});
    }
    for(i=0; i<n; i++)
    {
        h[i] = i;
        while(!pq.empty())
        {
            node t = pq.top(); pq.pop();
            if(h(t.st)!=h(t.fi))
        }
    }
}
