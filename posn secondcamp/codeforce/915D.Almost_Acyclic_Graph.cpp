#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2;
vector<int>vec[505];
int main(){
    scanf("%d%d",&V,&E);
    for(i = 1 ; i <= E ; i++){
        scanf("%d%d",&t1,&t2);
        vec[t1].push_back(t2);
    }   

} 