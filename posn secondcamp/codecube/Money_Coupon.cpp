//https://www.codecube.in.th/task/157
#include<bits/stdc++.h>
using namespace std;
char c;
int k;
int j,z,i,n;
bool x ;
long long ans,ans1;
int main(){
    long long cnt = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c%d",&c,&k);
        if(c=='+') ans+= k;
        if(c=='-') ans1 += k;
        if(c=='x'&&k==0) x = true;
        if(c=='x'&&k!=0) cnt*=k;
    }
    if(x) ans1 = 0;
    printf("%lld",ans*cnt-ans1);
}