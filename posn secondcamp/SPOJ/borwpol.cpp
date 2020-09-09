#include <bits/stdc++.h>
using namespace std;

int N1[205],N2[205],mem[205][205][205],n;
int bow(int x,int lis,int lds)
{
    if(x==n+1) return 0;
    if(mem[x][lis][lds])return mem[x][lis][lds];
    if(N1[lis]<N1[x])mem[x][lis][lds]=max(mem[x][lis][lds],bow(x+1,x,lds)+1);
    if(N2[lds]>N2[x])mem[x][lis][lds]=max(mem[x][lis][lds],bow(x+1,lis,x)+1);
    mem[x][lis][lds]=max(mem[x][lis][lds],bow(x+1,lis,lds));
    return mem[x][lis][lds];
}
int main(){
    while(1)
    {
    cin >> n;
    if(n==-1)return 0;
    for(int i=1;i<=n;i++)
    {
        cin >> N1[i];
        N2[i]=N1[i];
    }
    N1[0]=-1e9;
    N2[0]=1e9;
    cout << n-bow(1,0,0) << endl;
    fill(&N1[0],&N1[204],0);
    fill(&N2[0],&N2[204],0);
    fill(&mem[0][0][0],&mem[204][204][204],0);
    }
}

