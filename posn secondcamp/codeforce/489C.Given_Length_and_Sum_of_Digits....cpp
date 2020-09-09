#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,tmp,tmp2,c,val1,val2;
int arr[105],arr2[105];
int main(){
    scanf("%d%d",&N,&M);
    tmp = M;
    for(i = 1 ; i <= N ; i++){
        for(j = 0 ; j <= 9 ; j++){
            if(i==1 && j==0) continue;
            tmp2 = tmp - j;
            if(tmp2 < 0) continue;
            if(9 * (N - i) >= tmp2) {arr[c++] = j; val1 += j; break;}
        }
        tmp -= j;
    }
    tmp = M, c = 0;
    for(i = 1 ; i <= N ; i++){
        for(j = 9 ; j >= 0 ; j--){
            if(i==1 && j==0) continue;
            tmp2 = tmp - j;
            if(tmp2 < 0) continue;
            if(9 * (N - i) >= tmp2) {arr2[c++] = j; val2 += j; break;}
        }
        tmp -= j;
    }
    if(val1!= M || val2 != M) {printf("-1 -1"); return 0;}
    for(i = 0 ; i < N ; i++) printf("%d",arr[i]);
    printf(" ");
    for(i = 0 ; i < N ; i++) printf("%d",arr2[i]);
}