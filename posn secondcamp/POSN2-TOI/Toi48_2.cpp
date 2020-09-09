#include<bits/stdc++.h>
using namespace std;
int i,N,k;
int mem[5005][15005],wei[5005],val[5005];
int toi(int col,int limit){
   // cout << limit <<" "<< col << endl;
    if(col==N || limit <=0) return 0;
    if(mem[col][limit]) return mem[col][limit];
    int t = 0;
    for(int i = col;i<N;i++){
        if(limit>=wei[i]*8){
            t = toi(col+1,limit-wei[i]*8)+val[i];
            if(t>mem[col][limit]){
                //cout << t<<" " << mem[col][limit] << endl;
                mem[col][limit] = t;
            }
        }
    }
    return mem[col][limit];
}
int main(){
    scanf("%d%d",&N,&k);
    for(i=0;i<N;i++) scanf("%d",&val[i]);
    for(i=0;i<N;i++) scanf("%d",&wei[i]);
    cout << toi(0,k);
}