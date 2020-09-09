#include<bits/stdc++.h>
using namespace std;
int power,a[10],i,temp = 1e9 ,idx = -1;
bool used[10],found;
int main(){
	scanf("%d",&power);
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		if( i!=0 && power >= a[i] && a[i]<=temp){
			temp = a[i];
			idx = i;
		}
	}
	if(idx==-1) {printf("-1"); return 0;}
	for(i=0;i<power/temp;i++) printf("%d",idx);
	used[idx] = true;
    //printf("%d %d",minn,idx);
    power  -= temp*(power/temp);
	if(!power) 
	while(1){
        temp = 1e9;
        bool found = false;
		for(i=0;i<10;i++){
			if(!used[i] && power >= a[i] && a[i]<=temp){
					temp = a[i];
					idx = i;
                    found = true;
			}
		}
        if(!found) break;
		for(i=0;i<power/temp;i++) printf("%d",idx);
		power -= temp*(power/temp),used[idx] = true;    
	}
}