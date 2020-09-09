#include<bits/stdc++.h>
using namespace std;
int V,E,K,i,u,v,cnt;
int a[50005],h[50005],x[70005],y[70005],z[70005];
int  visited[50005];
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
bool find(int val){
    for(i=1;i<=V;i++){
        h[i] = i;
        visited[i] = 0;
    }
    for(i=1;i<=E;i++){
        if(z[i]>val) h[head(x[i])] = head(y[i]);
    }
    
    for(i=1;i<=V;i++){
        if(!visited[a[i]]) visited[a[i]] = head(i);
        else if(visited[a[i]]!=head(i)) return false;
    }
    return true;
}
int main(){
    scanf("%d%d%d",&V,&E,&K);
    for(i=1;i<=V;i++) scanf("%d",&a[i]);
    for(i=1;i<=E;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);  
    int l = 0,r = 1e9,mid;
    while(l<=r){
        mid = l+r >> 1;
        u = find(mid),v = find(mid+1);
        //printf("mid = %d\n",mid);
        if(u&&!v) break;
        else if(u&&v) l = mid+1;
        else r = mid-1;
    }
    for(i=1;i<=E;i++){
        if(z[i]<=mid) cnt++;
    }
    printf("%d",cnt);
}
