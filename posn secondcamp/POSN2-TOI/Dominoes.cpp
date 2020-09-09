#include<bits/stdc++.h>
using namespace std;
int n,a[15];
void domino(int x,int y){
    if (y > n) return;
    if (y == n){
        for (int i = 0; i < x; i++){
            printf(a[i]?"||\n":"--\n");
        }
        printf("E\n");
        return;
    }
    a[x] = 0;
    domino(x+1,y+1);
    a[x] = 1;
    domino(x+1,y+2);
}
int main(){
    scanf("%d",&n);
    domino(0,0);
}