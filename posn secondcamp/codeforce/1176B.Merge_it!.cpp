#include<bits/stdc++.h>
using namespace std;
int N,tc,i,cnt,arr[3],x;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        cnt = 0;
        for(i = 1 ; i <= N ; i++){
            scanf("%d",&x);
            arr[x%3]++;
        }
        cnt += arr[0];
        if(arr[1]>=arr[2]){
            cnt += arr[2];
            arr[1] -= arr[2];
            cnt += arr[1]/3;
        }
        else {
            cnt += arr[1];
            arr[2] -= arr[1];
            cnt += arr[2]/3;
        }
        printf("%d\n",cnt);
        for(i = 0 ; i <= 2 ; i++) arr[i] = 0;
    }
}