#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2,t3,u,v,cnt;
int h[100005],rnk[100005],Q;
long long val;
struct axis{
	int x,y,val,ber;
	bool operator < (axis k) const {
		return k.val > val;
	}
}t;
int head(int x){
	if(h[x]==x) return x;
	return h[x] = head(h[x]);
}
bool mark[100005],cloop;
vector<int>ans;
priority_queue<axis>heap;
int main(){
	scanf("%d%d",&V,&E);
	for(i = 1 ; i <= V ; i++) h[i] = i,rnk[i] = 1;
	for(i = 1 ; i <= E ; i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		heap.push({t1,t2,t3,i});
	}
	scanf("%d",&Q);
	while(!heap.empty()){
		t = heap.top(); heap.pop();
		u = head(t.x), v = head(t.y);
		if(u!=v){
			h[u] = v;
			val += t.val;
			cnt++;
			ans.push_back(t.ber);
		}
		else if(!cloop){
			cloop = true;
			val += t.val;
			cnt++;
			ans.push_back(t.ber);
		}
	}
	if(cnt!=V) {printf("-1"); return 0;}
	printf("%lld\n",val);
	if(Q==2){
		for(i = 0 ; i < ans.size() ; i++)
			printf("%d ",ans[i]);
	}
}