#include<bits/stdc++.h>
using namespace std;
int N,i,tmp;
long long val;
vector<int>v1,v2;
int main(){
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++){
        scanf("%d",&tmp);
        v1.push_back(tmp);
    }
    sort(v1.begin(),v1.end());
    for(i = 0 ; i < N ; i++){
        scanf("%d",&tmp);
        v2.push_back(tmp);
    }
    sort(v2.rbegin(),v2.rend());
    for(i = 0 ; i < N ; i++) 
        v1[i] += v2[i];
    sort(v1.begin(),v1.end());
    for(i = 1 ; i < N ; i++) val += v1[i] - v1[i-1];
    printf("%lld",val);

}