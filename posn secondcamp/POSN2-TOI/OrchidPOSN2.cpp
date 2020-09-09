#include<bits/stdc++.h>
using namespace std;
int N,i,a[1000005],t1,t2,l,r,mid,pos;
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&t1);
        if(t1>=a[pos]){
            a[++pos] = t1;
        }
        else {
            int k = upper_bound(a+1,a+pos+1,t1)-a;
            a[k] = t1;
        }
    }
    printf("%d",N-pos);
}