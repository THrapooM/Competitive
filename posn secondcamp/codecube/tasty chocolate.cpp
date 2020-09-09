#include<bits/stdc++.h>
using namespace std;
int N,arr[1005],i,mem[1005][3005];
int choco(int pos,int val){
        if(pos==N+1) return 0;
        if(mem[pos][val]) return mem[pos][val];
        mem[pos][val] = 1e9;
        if(val > 3000) return 1e9;
        mem[pos][val] = choco(pos+1,val+1)+1;
        if(arr[pos] > val)
        mem[pos][val] = min(mem[pos][val],min(choco(pos+1,arr[pos]),choco(pos+1,val+1)+1));
        return mem[pos][val];
}
int main(){
        scanf("%d",&N);
        for(i = 1 ; i <= N ; i++)
                scanf("%d",&arr[i]);
        printf("%d",choco(1,0));
}