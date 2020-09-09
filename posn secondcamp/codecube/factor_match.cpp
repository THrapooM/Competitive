#include<bits/stdc++.h>
using namespace std;
int tpk[100005],i,j,mem[1000005],t1,letsfind[1000005],maxx=-1,n,m;
int p[1000005];
void kmppreprocess(){   
	int i=0,idx=-1;
	p[0] = -1;
	for(i=0;i<m;){
		while(idx>=0 && letsfind[i]!=letsfind[idx]) idx = p[idx];
		i++,idx++,p[i] = idx;
	}
}
void kmp(){
	int i=0,idx=0;
	while(i<n){
		while(idx>=0 && mem[i]!=letsfind[idx]) idx = p[idx];
		if(n-i>=m-idx) maxx = max(idx,maxx); 
		i++,idx++;
	}
}
int main(){
	for(i=1;i<=100000;i++){
		for(j=1;j<sqrt(i);j++){
			if(i%j==0) tpk[i]+=2;
		}
		if(i==j*j)tpk[i]++;
	}
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&t1);
		mem[i] = tpk[t1];
	}
	for(i=0;i<m;i++){
		scanf("%d",&t1);
		letsfind[i] = tpk[t1];
	}
	kmppreprocess();
	kmp();
	printf("%d",maxx+1);
}