#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int N,M,K,T,i,t1,t2,t3,t4,l,r,mid,mem[100005],tmp;
bool check;
struct axis{
	int x,danger,tim;
	bool operator < (axis k) const {
		return k.tim < tim;
	}
};
struct axis2{
	int x,y;
}a[100005];
bool cmp(axis2 x,axis2 y){
	if(x.y==y.y) return x.x < y.x;
	return x.y < y.y;
}
priority_queue<axis>heap;
vector<axis>from[100005];
bool dylta(int x){
	for(int i = 1 ; i <= N ; i++) mem[i] = inf;
	int tx,tval,tdan;
	heap.push({1,a[x].y,0});
	mem[1] = 0;
	while(!heap.empty()){
		axis t = heap.top(); heap.pop();
		for(int i = 0 ; i < from[t.x].size() ; i++){
			tx = from[t.x][i].x;
			tval = from[t.x][i].tim + t.tim;
			tdan = from[t.x][i].danger;
			if(tdan <= t.danger && mem[tx] > tval && tval <= T){
				mem[tx] = tval;
				heap.push({tx,t.danger,tval});
			}
		}
	}
	if(mem[N]==1e9) return 0;
	else return 1;
}
int main(){
	scanf("%d%d%d%d",&N,&M,&K,&T);
	for(i = 1 ; i <= M ; i++){
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		from[t1].push_back({t2,t3,t4});
		from[t2].push_back({t1,t3,t4});
	}
	for(i = 1 ; i <= K ; i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+K+1,cmp);
	l = 1,r = K;
	while(l <= r){
		mid = (l+r) >> 1;
		check = dylta(mid);
		if(check){
			r = mid-1;
		}
		else l = mid+1;
	}
//	printf("%d %d %d",l,r,mid);
	tmp = a[l].y;
	if(tmp==0) {printf("-1"); return 0;}
	int minn = inf;
	for(i = 1 ; i <= K ; i++){
		if(a[i].y >= tmp){
			minn= min(minn,a[i].x);
		}
	}
	printf("%d",minn);
}