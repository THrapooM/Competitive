#include<bits/stdc++.h>
using namespace std;
int mx=-1e9,mid1,mid2;
int n,m,a[1000005];
int eng(int x){
    int val = 0;
    int cnt = 0;
    for(int j=0;j<n;j++){
        if(x<a[j]) return 0;
        if(val < a[j]){
            cnt++;
            val = x;
        }
        val -= a[j];
    }
    return cnt;
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        mx = max(mx,a[i]);
    }
    if(m==1){
        printf("-1");
        return 0;
    }
    int bot1 = mx,bot2 = mx;
    int top1 = 1e9,top2 = 1e9;
    while(1){
        mid1 = (bot1+top1)>>1;
        if(eng(mid1)==m && eng(mid1+1)!=m) break;
        else if(eng(mid1)>=m) bot1 = mid1+1;
        else if(eng(mid1)<m) top1 = mid1-1;
     }
     //cout << mid1;
     while(1){
         mid2 = (bot2+top2)>>1;
         if(eng(mid2)==m && eng(mid2-1)!=m) break;
         else if(eng(mid2)<=m) top2 = mid2-1;
         else if(eng(mid2)>m) bot2 =mid2+1;
     }
     //cout << mid2;
    printf("%d",mid1-mid2+1);
}
