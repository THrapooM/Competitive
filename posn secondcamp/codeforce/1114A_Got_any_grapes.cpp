#include<bits/stdc++.h>
using namespace std;
int x,y,z,i,j,k;
int main(){
    scanf("%d%d%d",&x,&y,&z);
    scanf("%d%d%d",&i,&j,&k);
    if(x > i) {printf("NO"); return 0;}
    i -= x;
    if(j+i < y) {printf("NO"); return 0;}
    j = j+i-y;
    if(j+k < z) {printf("NO"); return 0;}
    printf("YES"); 
}