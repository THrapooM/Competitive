#include<bits/stdc++.h>
using namespace std;
int N,k,i,j,a[105],t1,t2;
 vector<int>v;
int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d",&t1,&t2);
        v.push_back(t1);
    }
    scanf("%d",&k);
    for(i=0;i<v.size();i++){
        if(k<v[i]) break;
    }
    printf("%d",N-i+1);
}