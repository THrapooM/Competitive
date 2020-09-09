#include<bits/stdc++.h>
using namespace std;
int i,a[100005],tc,t1;
int main(){
    double x = 1;
    for(i=1;i<=100000;i++){
        x += log10(i);
        a[i] = x;
    }
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&t1);
        printf("%d\n",a[t1]);
    }
}