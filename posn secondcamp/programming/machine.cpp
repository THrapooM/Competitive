#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>pq;
long long mem[300005];
int main()
{
    int n;
    int i;
    long long x;
    cin >> n;
    char inp;
    int k=0;
    for(i=0; i<n; i++)
    {
        scanf(" %c",&inp);
        if(inp=='P')
        {
            scanf("%lld",&x);
            pq.push(x);
        }
        else if(inp=='Q')
        {
            if(!pq.empty())
            {
                printf("%lld\n",pq.top());
                pq.pop();
            }
            else
            {
                printf("-1\n");
            }

        }
    }

}
