#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n,k,i,j,x,y;
int m[N],fm[N];
bool found;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){ 
		scanf("%d%d",&m[i],&fm[i]); 
	}
	for(i=1;i<=n;i++){
		if(i-k<1) y = 1;
		else y = i-k;
		if(i+k>n) x = n;
		else x = i+k;
		for(j=y;j<=x;j++){
			if(m[i]-fm[j]>=0){
				m[i] -= fm[j];
				fm[j] = 0;
			}
			else {									  
				fm[j] -= m[i];
				m[i]  = 0;
			}
		}
        for(j=y;j<=x;j++){
            if(fm[i]-m[j]>=0){
                fm[i] -= m[j];
                m[j] = 0;
            }
            else {
                m[j] -= fm[i];
                fm[i] = 0;
            }
        }
		if(m[i]||fm[i]) {printf("NO"); return 0;}
	}
	//if(fm[n]) printf("NO");
	printf("YES");
}   