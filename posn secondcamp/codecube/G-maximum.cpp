#include<bits/stdc++.h>
using namespace std;
int N,arr[1000005],i,val[1000005],t;
stack<int>sl,sr;
int main(){
    scanf("%d",&N);
   arr[0] = 1e9;
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&arr[i]);
        val[i] = 1;
    }
    arr[N+1] = 1e9;
    for(i = 1 ; i <= N+1 ; i++){
        while(!sr.empty() && arr[i] > arr[sr.top()]){
            t = sr.top() ; sr.pop();
           // printf("l > r %d\n",i-t-1);
            val[t] += i-t-1;
        }
        sr.push(i);
    }
    for(i = N ; i >= 0 ; i--){
        while(!sl.empty() && arr[i] > arr[sl.top()]){
            t = sl.top(); sl.pop();
           // printf("r > l %d\n",t-i-1);
            val[t] += t-i-1;
        }
        sl.push(i);
    }
    for(i = 1 ; i <= N ; i++){
        printf("%d ",val[i]);
    }
}