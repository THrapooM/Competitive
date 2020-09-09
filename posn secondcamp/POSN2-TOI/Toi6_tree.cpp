#include<bits/stdc++.h>
using namespace std;
int i,n,t1,t2;
set<int>myset[100005];
int main(){
    int tc = 5;
    while(tc--){
        bool found = false;
        int maxx = 0;
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d%d",&t1,&t2);
            myset[t1].insert(t2);
            myset[t2].insert(t1);
            maxx = max(maxx,max(t1,t2));
        }
        for(i=0;i<n-1;i++){
            scanf("%d%d",&t1,&t2);
            if(myset[t1].find(t2)==myset[t1].end()) found = true;
        }
        if(found) printf("N");
        else printf("Y");
        for(i=1;i<=maxx;i++) myset[i].clear();
    }
}