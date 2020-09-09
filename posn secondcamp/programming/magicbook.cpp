#include<bits/stdc++.h>
using namespace std;
int N,i,j,q,x,y;
int a[1000005],tmp,sum[1000005];
int main(){
    scanf("%d",&N);
    sum[1] = 0;
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&a[i]);
        if(i > 1){
            if(a[i] < a[i-1]) tmp = 0;
            else tmp = a[i] - a[i-1];
            sum[i] += sum[i-1] + tmp;
        }
    }
    scanf("%d",&q);
    for(i = 1; i <= N ; i++){
        printf("sum[%d] = %d\n",i,sum[i]);
    }
    for(i = 1 ; i <= q ; i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",sum[y] - sum[x]);
    }
}