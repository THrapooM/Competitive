#include <bits/stdc++.h>
using namespace std;

map<int,map<int,int>>mem;
int N,M,K,T;
int a,b,c,d;
int visited[100005];
//int visited2[100005];
struct node{
	int x,dg,tim,bef;
	bool operator < (node t) const{
		if(t.dg==dg)return t.tim<tim;
		return t.dg<dg;
	}
};

struct shoes{
	int price,strength;
	bool operator < (shoes t) const{
		return t.price > price;
	}
};

vector <node> v[100005];
vector <shoes> ps;
priority_queue<node>pq;

int main(){
	scanf("%d%d%d%d",&N,&M,&K,&T);
//	fill(&visited2[0],&visited2[100004],2e9-5);
	fill(&visited[0],&visited[100004],2e9-5);
	int dmax=0;
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		v[a].push_back({b,c,d});
		v[b].push_back({a,c,d});
	}
	for(int i=0;i<K;i++)
	{
		scanf("%d%d",&a,&b);
		ps.push_back({a,b});
		dmax=max(dmax,b);
	}
	sort(ps.begin(),ps.end());
	pq.push({N,0});//t.val->t.dg
	while(!pq.empty())
	{
		node t=pq.top();pq.pop();
		if(visited[t.x]!=2e9-5)continue;
		visited[t.x]=t.dg;
		for(int i=0;i<v[t.x].size();i++) pq.push({v[t.x][i].x,t.dg+v[t.x][i].tim});
	}
//	printf("%d\n",visited[N]);
	while(!pq.empty())pq.pop();
	pq.push({1,0,0,0});
//	mem[99999][99999]=1;
	while(!pq.empty()){
		node t=pq.top();pq.pop();
//		printf("t.x=%d\n",t.x);
		if(t.dg>dmax)continue;
		if(t.tim+visited[t.x]>T)continue;
		if(mem[t.x][t.dg]&&mem[t.x][t.dg]<=t.tim)continue;
		mem[t.x][t.dg]=t.tim;
//		if(visited2[t.x]<=t.dg)continue;
//		visited2[t.x]=t.dg;
		if(t.x==N)
		{
			int mon=2e9-5;
			for(int i=0;i<ps.size();i++)
			{
				if(ps[i].strength<t.dg)continue;
				mon=min(mon,ps[i].price);
			}
			printf("%d",mon);
			return 0;
		}
		for(int i=0;i<v[t.x].size();i++)
		{
			if(v[t.x][i].x==t.bef)continue;
			pq.push({v[t.x][i].x,max(t.dg,v[t.x][i].dg),t.tim+v[t.x][i].tim,t.x});
		}
	}
	printf("-1");
}
