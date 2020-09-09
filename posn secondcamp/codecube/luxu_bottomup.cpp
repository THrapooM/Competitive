#include<bits/stdc++.h>
using namespace std;
int N,M,K,arr[100005],i,mem[2][100005],j,k,val;
bool flag;
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&arr[i]);
        arr[i] += arr[i-1];
    }
    if(M*K>=N) printf("%d",arr[N]);
    else {
        for(i = 1 ; i <= M ; i++){
            flag = !flag;
            for(j = K ; j <= N ; j++){
                mem[flag][j] = mem[flag][j-1];
                mem[flag][j] = max(mem[flag][j],mem[!flag][j-K] + arr[j] - arr[j-K]);
                val = max(val,mem[flag][j]);
            }   
        }
        printf("%d",val);
    }
}
