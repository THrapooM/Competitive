//https://www.codecube.in.th/task/13
#include<bits/stdc++.h>
using namespace std;
int i,a[1005],n,k,mem[1005][305];
int qsum(int x,int y){
    return a[y] - a[x-1];
}
int parti(int pos,int zone){
        if(pos==n+1 && zone==k+1) return 0;
        if(zone > k+1) return mem[pos][zone] = 1e9;
        if(mem[pos][zone]) return mem[pos][zone];
        mem[pos][zone] = 1e9;
        for(int i=pos;i<=n;i++){
            mem[pos][zone] = min(mem[pos][zone],max(qsum(pos,i),parti(i+1,zone+1)));
            //printf("mem[%d][%d] = %d\n",pos,zone,mem[pos][zone]);
        }
        return mem[pos][zone];
}
int main(){
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }

    cout << parti(1,1);
}
