#include<bits/stdc++.h>
using namespace std;
int main(){
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }

}
