//https://codeforces.com/problemset/problem/115/A
#include<bits/stdc++.h>
using namespace std;
int N,a[2005],maxx=-1e9,t,cnt=0,i;
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=N;i++){
        t = a[i];
        cnt = 0;
        while(t!=-1){
            t = a[t];
            cnt++;
        }
        maxx  = max(maxx,cnt);
    }
    printf("%d",maxx+1);

    
}