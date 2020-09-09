#include<bits/stdc++.h>
using namespace std;
long long sum,x;
map<int,long long>m;
long long f(int n){
    if(n==0) return 0;
    if(m[n]) return m[n];
    sum = f(n/2)+f(n/3)+f(n/4);
    if(sum>n) m[n] = sum;
    else m[n] = n;
    return m[n];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",f(n));
    }
    return 0;
}
