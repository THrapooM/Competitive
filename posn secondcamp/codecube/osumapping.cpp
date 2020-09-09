//https://www.codecube.in.th/task/185
#include<bits/stdc++.h>
#define inf 1e17
using namespace std;
struct node{
	int x; long long val;
	int multi;
	bool operator < (node k) const{
	return k.val < val;
	}
}t;
vector<node>from[10005];
priority_queue<node>heap;
int V,E,T,t1,t2,t3,t4,st,fi,i;
bool visited[10005][10];
long long mem[10005][10];
int main(){
	fill(&mem[0][0],&mem[10004][9],inf);
	scanf("%d%d%d",&V,&E,&t4);
	scanf("%d%d",&st,&fi);
	for(i=0;i<E;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		from[t1].push_back({t2,t3});
		//[t2].push_back({t1,t3,1});
	}
	mem[st][1] = 0;
	heap.push({st,0,1});
	while(!heap.empty()){
		t = heap.top(); heap.pop();
		if(visited[t.x][t.multi]) continue;
		visited[t.x][t.multi] = true;
		int tmulti = (t.multi+1)%t4;
		for(i=0;i<from[t.x].size();i++){
			long long tval = t.val + from[t.x][i].val;
			int tx = from[t.x][i].x;
			if(visited[tx][tmulti]) continue;
			if(mem[tx][tmulti]>tval){
				mem[tx][tmulti] = tval;
				heap.push({tx,mem[tx][tmulti],tmulti});
			}
		}
	}
	if(mem[fi][0]!=1e17){
			printf("%lld",mem[fi][0]); return 0;
		}
	 else printf("-1");
}
