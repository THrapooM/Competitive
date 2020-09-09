#include <bits/stdc++.h>
using namespace std;
int a[30],v[30],i,n,val = 1e9,t;
void f(int x){
    if (x == n){
        t = 0;
        for (i = 0; i < n; i++){
            if (a[i]) t += v[i];
            else t -= v[i];
        }
        val = min(val,abs(t));
    }
    else{
        a[x] = 0;
        f(x+1);
        a[x] = 1;
        f(x+1);
    }
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&v[i]);
    f(0);
    cout << val;
}
