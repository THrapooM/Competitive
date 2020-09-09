//https://www.codecube.in.th/task/29
//https://www.geeksforgeeks.org/modular-exponentiation-recursive/
#include<stdio.h>
using namespace std;
int t1,i,n,t2,y;
int  find(int x){
    if(x==0) return 1;
    else if(x%2==0){
        y = find(x/2)%997;
        y = (y*y)%997;
    }
    else y = (4*(find(x-1)%997))%997;
    return y%997;
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t1);
        y = 0;
		find(t1);
		if(t1%2==0)t2 = 2;
		else t2 = -2;
		printf("%d ",(y+t2)%997);
	}
}