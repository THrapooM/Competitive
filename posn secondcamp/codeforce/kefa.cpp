//https://codeforces.com/problemset/problem/580/A
#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n,i;
int lis(int x,int val){
    int cnt=0;
    if(x==n) return 0;
    if(a[x]>=val) cnt = lis(x+1,a[x])+1;
    else return max(cnt,lis(x,a[x]));

}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",lis(0,-1e9));
}
