#include<bits/stdc++.h>
using namespace std;
int n,a[15];
void luktao(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else {for(int j=1;j<=6;j++){
            a[x] = j;
            luktao(x+1);
    }
}
}
int main(){
    scanf("%d",&n);
    luktao(1);
}