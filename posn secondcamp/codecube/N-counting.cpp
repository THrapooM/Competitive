#include<bits/stdc++.h>
using namespace std;
int N,Q,t1,stidx,enidx,fv,lv;
vector<int>pos;
int main(){
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++){
        scanf("%d",&t1);
        pos.push_back(t1);
    }
    while(Q--){
        scanf("%d%d%d%d",&stidx,&enidx,&fv,&lv);
        auto l = lower_bound(pos.begin()+stidx-1,pos.begin()+enidx,fv);
        auto r = lower_bound(pos.begin()+stidx-1,pos.begin()+enidx,lv);
        printf("r = %d l = %d\n",r,l);
        printf("%d\n",r-l);
    }
}