#include<bits/stdc++.h>
using namespace std;
int a[1005],c[1005],t1,i,N,M,K,j,cnt;
map<int,bool>b;
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    for(i=0;i<M;i++) {scanf("%d",&t1);
    b[t1] = true;}
    for(i=0;i<K;i++) scanf("%d",&c[i]);
    sort(c,c+K);
    for(i=0;i<K;i++){
        for(j=0;j<N;j++){
             if(c[i]-a[j]<0) break;
            else if(b[c[i]-a[j]]){
                cnt++;
                //printf("%d %d\n",c[i],a[j]);
                break;
        }
        }
    }
    cout << cnt;
}