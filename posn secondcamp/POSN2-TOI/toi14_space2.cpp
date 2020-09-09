#include<bits/stdc++.h>
using namespace std;
int i,n,m,j;
int a[10005][2005];
string s;
int main(){
    scanf("%d%d",&n,&m);
    for(i = 1 ; i <= m ; i++){
            cin >> s;
            for(j = 1 ; j <= n ; j++){
                a[i][j] = !(s[j-1]-'0');
                a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
            }
    }
    printf("\n\n");
    for(i = 1; i <= m ;i++){
        for(j = 1 ; j <= n ;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}