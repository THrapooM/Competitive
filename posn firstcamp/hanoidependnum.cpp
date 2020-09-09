#include <bits/stdc++.h>
using namespace std;
int a[100][1000];
int n,N,c;
int i,j,p;
int y,space;
int main(){
    scanf("%d",&n);
    N = n;
    while (N - ++c > 0) N -=c;
    //cout << N << " " << c << " ";
    y = 2*c;
    if (c%2 && c - N <= 2) space = N-1;
    else if (c%2) space = c-3;
    else space = c-2;
    //cout << space;
    for (i = 0; i < c; i++){
        if (i%2){
            for(j = space; j <= i+space; j++)
                if (n--) a[i][j] = (p++%26)+'A';
                else break;
        }
        else{
            for(j = space; j >= space-i; j--)
                if (n--) a[i][j] = (p++%26)+'A';
                else break;
        }
    }
    for (i = 0; i < c; i++){
        for (j = 0; j < y; j++){
            if(a[i][j]) printf("%c ",a[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
}
