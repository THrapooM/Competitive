#include<iostream>
using namespace std;
int n,m,k,a[1005],i;
int mem[1005][105];
int qsum(int x,int y){
	return a[y] - a[x-1];
}
int luxu(int pos,int hotel){
	if(pos>=n+1||hotel==m) return 0;
	if(hotel > m) return -555555;
	if(mem[pos][hotel]) return mem[pos][hotel];
    mem[pos][hotel] = luxu(pos+1,hotel);   
	for(int i=0 ; i<k ; i++){
		mem[pos][hotel] = max(mem[pos][hotel],qsum(pos,pos+i)+luxu(pos+i+1,hotel+1));
	}
	return mem[pos][hotel];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]),a[i]+=a[i-1];
	}
	printf("%d",luxu(1,0));
}