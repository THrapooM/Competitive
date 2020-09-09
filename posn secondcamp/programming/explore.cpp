//https://programming.in.th/task/rev2_problem.php?pid=1085
#include<bits/stdc++.h>
using namespace std;
int n,m,k,mem[500005],go,exitt,maxx=-1e9,i,cg,t;
queue<int>q;
vector<int>v[500005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(mem,1,sizeof(mem));
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&go,&exitt);
        v[go].push_back(exitt);
    }
    for(i=0; i<k; i++)
    {
        scanf("%d",&cg);
        mem[cg] = 0;
    }
    q.push(1);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        maxx = max(maxx,t);
        if(t==n)
        {
            printf("1");
            return 0;
        }
        for(i=0;i<v[t].size();i++) q.push(v[t][i]);
        if(!mem[t]) continue;
        q.push(t+1);
    }
    printf("0 %d",maxx);


}
