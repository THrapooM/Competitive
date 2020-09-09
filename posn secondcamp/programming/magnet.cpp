#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int N,M,K,i,t1,t2,x;
vector<int>v;
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(i = 1 ; i <= M ; i++){
        scanf("%d%d",&t1,&t2);
        v.push_back(t1);
        v.push_back(t1+t2);
    }
    sort(v.begin(),v.end());
    for(i = 0 ; i < x ; i++){
        if(v[i]==v[i-1]){
            v[i] = inf;
            v[i-1] = inf;
        }
    }
    v.push_back(1);
    v.push_back(N+1);
    sort(v.begin(),v.end());
   // for(i = 0 ; i < v.size() ; i++) printf("v[%d] = %d\n",i,v[i]);
    while(K--){
        scanf("%d",&t1);
        auto up = upper_bound(v.begin(),v.end(),t1)-v.begin();
        printf("%d\n",v[up]-v[up-1]);
        
    }
}