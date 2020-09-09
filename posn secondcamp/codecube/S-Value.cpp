#include<bits/stdc++.h>
using namespace std;
int n,i;
long long int val;
int a[2005];
int main(){
    scanf("%d",&n);     
    for(i=0;i<n*2;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+2*n);
    for(i=0;i<n;i++){
        val += (long long)a[i]*a[(n*2)-1-i];
    }
     printf("%lld",val);

}