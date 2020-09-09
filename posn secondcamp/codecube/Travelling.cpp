//https://www.codecube.in.th/task/51
#include<bits/stdc++.h>
using namespace std;
int V,E,K,city[20],t1,t2,t3,i,j,k,check = 0,minn = 1e9;
int dis[205][205];
struct axis{
	int x,val,pass;
}t;
queue<axis>que;
int main(){
	scanf("%d%d%d",&V,&E,&K);
	city[1] = 1;
	city[K+2] = V;
	check = (1 << (K+2))-2;
	for(i=2;i<=K+1;i++){
		scanf("%d",&t1);
		city[i] = t1;
	}
	fill(&dis[0][0],&dis[204][204],1e9);
	for(i=1;i<=E;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		dis[t1][t2] = t3;
		dis[t2][t1] = t3;
		dis[t1][t1] = 0;
		dis[t2][t2] = 0;
	}
	for(i = 1; i <= V ; i++)
		for(j = 1; j <= V; j++)
			for(k = 1; k <= V; k++)
			dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
	que.push({1,0,0});
	while(!que.empty()){
		t = que.front(); que.pop();
		if(t.x==K+2 && t.pass==check){
			minn = min(minn,t.val);
			continue;
		}
		//printf("t.x = %d t.val = %d t.pass = %d\n",t.x,t.val,t.pass);
		for(i=2;i<=K+2;i++){
			if(((1<<(i-1))&t.pass)==0){
				 //printf("%d from %d to %d val1 = %d val2 = %d pass = %d\n",t.x,city[t.x],city[i],t.val,dis[city[t.x]][city[i]],t.pass);
				que.push({,t.val + dis[city[t.x]][city[i]],t.pass|(1<<(i-1))});
			}
		}
	}
	printf("%d",minn);
	
}