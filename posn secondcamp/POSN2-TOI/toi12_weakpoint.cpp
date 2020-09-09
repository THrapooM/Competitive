#include<bits/stdc++.h>
using namespace std;
int N,Cp,i,t1,t2;
vector<int>from[500005];
int h[500005];
int main(){
    scanf("%d%d",&N,&Cp);
    
   for(i = 1 ; i <= N ; i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
    }
    for(i = 0 ; i < from[Cp].size() ; i++){
        h[from[Cp][i]] = from[Cp][i];
        
    }
    
    
}