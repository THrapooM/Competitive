#include<bits/stdc++.h>
using namespace std;
vector <int> v[105];
    int i,j,x,y;
    int n;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
    }
    for(i=100;i>=0;i--)
    {
        for(j=0;j<v[i].size();j++)
            printf("%d %d\n",v[i][j],i);
    }
}
