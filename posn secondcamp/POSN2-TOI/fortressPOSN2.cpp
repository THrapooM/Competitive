#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,lf,rt;
};
int n,m,u,v,l,r,ans=0;
char c[2005][2005];
deque<node> dq;
signed main(){
	cin>>n>>m>>u>>v>>l>>r;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[i][j];
	dq.push_back({u,v,l,r});
	while(!dq.empty()){
		node p=dq.front();
		dq.pop_front();
		if(c[p.x][p.y]!='.') continue;
		c[p.x][p.y]='*';
		ans++;
		if(p.x>1&&c[p.x-1][p.y]=='.') dq.push_front({p.x-1,p.y,p.lf,p.rt});
		if(p.x<n&&c[p.x+1][p.y]=='.') dq.push_front({p.x+1,p.y,p.lf,p.rt});
		if(p.y>1&&c[p.x][p.y-1]=='.'&&p.lf>0) dq.push_back({p.x,p.y-1,p.lf-1,p.rt});
		if(p.y<m&&c[p.x][p.y+1]=='.'&&p.rt>0) dq.push_back({p.x,p.y+1,p.lf,p.rt-1});
	}
	cout<<ans;
}