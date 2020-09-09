#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,ans;
int p[105],sc[105],pmax[105];

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++){
      cin>>s[i];
      pmax[s[i]]=max(pmax[s[i]],p[i]);
    }
    for(int i=1;i<=k;i++){
      cin>>c;
      if(p[c]<pmax[s[c]])ans++;
    }
    cout<<ans;
    return 0;
}
