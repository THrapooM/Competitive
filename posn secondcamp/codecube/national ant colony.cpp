//https://www.codecube.in.th/task/165
#include<bits/stdc++.h>
using namespace std;
int V,E,K,i,t1,t2,t3,tx,tval;
bool u,v;
struct axis{																									
	int x,val;
}t;
vector<axis>from[50005];
vector<int>store[70005];
bool visited[50005];
int check[50005],cnt,a[70005];
void dfs(int st,int val,int mark){
	visited[st] = true;
	check[st] = mark;
	//printf("val = %d st = %d,mark = %d\n",val,st,mark);
	for(int i=0;i<from[st].size();i++){
		tx = from[st][i].x;
		tval = from[st][i].val;
		//printf("st = %d tx = %d val = %d tval = %d mark = %d\n",st,tx,val,tval,mark);
		if(!visited[tx] && tval > val) dfs(tx,val,mark);
	}
}
bool find(int val){
	for(i=1;i<=V;i++) visited[i] = false;
	bool found=false;
	for(int i=1;i<=V;i++)
		if(!visited[i]) dfs(i,val,i);
	int temp,ntemp;
	for(int i=1;i<=K;i++){
		if(store[i].size()>=1) temp = check[store[i][0]];
		for(int j=0;j<store[i].size();j++){
			ntemp = check[store[i][j]];
			if(ntemp!=temp) found = true;
		}
	}
	if(found) return false; 
	return true;
}
int main(){
	scanf("%d%d%d",&V,&E,&K);   
	for(i=1;i<=V;i++)
	scanf("%d",&t1),store[t1].push_back(i);
	for(i=1;i<=E;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		 from[t1].push_back({t2,t3});
		 from[t2].push_back({t1,t3});
		 a[i] = t3;
	}
	int l = 0,r = 1e9,mid;
	while(l<=r){
		mid = l+r >> 1;
		u = find(mid),v = find(mid+1);
		if(u&&!v) break;
		else if(u&&v) l = mid+1;
		else r = mid-1;
	}
	for(i=1;i<=E;i++){
		if(a[i]<=mid) cnt++;
	}
	printf("%d",cnt);
}