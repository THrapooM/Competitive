#include<bits/stdc++.h>
using namespace std;
long long tmp;
int cnt;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&tmp);
        cnt = 0;
        while(tmp%5==0) tmp/=5,tmp*=4,cnt++;
        while(tmp%3==0) tmp/=3,tmp*=2,cnt++;
        while(tmp%2==0) tmp/=2,cnt++;
        if(tmp==1) printf("%d\n",cnt);
        else printf("-1\n");
    }
}