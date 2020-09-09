#include <bits/stdc++.h>
using namespace std;

int mem[101];
int main(){
    int n,i;
    scanf("%d",&n);
    if (n < 6){
        printf("no");
        return 0;
    }

    mem[6] = 1, mem[9] = 1, mem[20] = 1;

    for (i = 6; i <= n; i++){
        if (mem[i]){
            mem[i+6] = 1;
            mem[i+9] = 1;
            mem[i+20] = 1;
        }
    }
    for (i = 1; i <= n; i++){
        if (mem[i]) printf("%d\n",i);
    }
}
