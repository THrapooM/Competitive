#include<bits/stdc++.h>
using namespace std;
int n,i,k;
int sum = 1;
int a[10005];
int main(){
    scanf("%d%d",&n,&k);
    int x = n;
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        a[i]++;
        if(a[i]>1) {a[i]--; k--;x--;}
    }
    cout << k << " "<< x;
    sort(a,a+x);
    for(i=0;i<n;i++) printf("%d ",a[i]);
    for(i=k;i<x;i++){
        sum |= a[i];
    }
    printf("%d",sum);

}