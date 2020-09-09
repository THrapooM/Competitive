#include <bits/stdc++.h>
using namespace std;
int a[3005],n,L,H,R,high=0,low=1e9,current;
int i,j;
int main(){
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%d%d%d",&L,&H,&R);
		high = max(high,R);
		low = min(low,L);
		for (j = L; j < R; j++) a[j] = max(a[j],H);
	}
	for (i = low-1; i < high; i++){
		if (a[i+1] != current){
			current = a[i+1];
			printf("%d %d ",i+1,a[i+1]);
		}
	}
}
