#include<bits/stdc++.h>
using namespace std;
int N,Q,i,j,st,fi,val,t1;
map<int,vector<int>>pos;
int main(){
    scanf("%d%d",&N,&Q);
    for(i=1;i<=N;i++){
        scanf("%d",&t1);
        pos[t1].push_back(i);
    }
    while(Q--){
        scanf("%d%d%d",&st,&fi,&val);
        auto l = lower_bound(pos[val].begin(),pos[val].end(),st);
        auto r = upper_bound(pos[val].begin(),pos[val].end(),fi);
        printf("%d\n",r-l);
    }
}