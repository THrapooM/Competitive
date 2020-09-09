#include<bits/stdc++.h>
using namespace std;
int N,i;
int a[100005],maxx=-1e9;
int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        maxx = max(max,a[i]);
        a[i]++;
    }
    for(i=0;i<=maxx;i++){
        
    }

}