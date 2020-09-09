#include<bits/stdc++.h>
using namespace std;
int n,a[1005],mem[200005],i,j,maxx=-1e9,z;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            z = a[i]+a[j];
            mem[z]++;
            maxx = max(mem[z],maxx);
        }
    }
    printf("%d",maxx);
}
