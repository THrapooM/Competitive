#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],max1=-1e9,max2=-1e9;
int n,i,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++) 
    scanf("%lld",&a[i]),a[i]+=a[i-1];
    for(i=1;i<=n;i++)
    scanf("%lld",&b[i]),b[i]+=b[i-1];
    for(i=m;i<=n;i++) max1 = max(max1,a[i]-a[i-m]);  
    for(i=k;i<=n;i++) max2 = max(max2,b[i]-b[i-k]);
    printf("%lld",max1*k+max2*m);        
}