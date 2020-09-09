//https://www.codecube.in.th/task/87
#include<bits/stdc++.h>
using namespace std;
int N,power,i,t1,a[1000005],maxx=-1e9,minn=1e9;
long long cnt;
int main(){
	scanf("%d%d",&N,&power);
	for(i=0;i<N;i++){
		scanf("%d",&t1);
		a[t1]++;
		maxx = max(maxx,t1);
		minn = min(minn,t1);
	}
	//for(i=minn;i<=maxx;i++) printf("i = %d",a[i]);
	for(i=minn;i<=maxx;i++){
		if(i>power-i) break;
		if(a[i] && a[power-i]){
			if(i!=power-i) cnt += (long long)(a[i]*a[power-i]);
			else cnt += (1ll*a[i]*(a[i]-1))/2;
		}
	}
	printf("%lld",cnt);
}