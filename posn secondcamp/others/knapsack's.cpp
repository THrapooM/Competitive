#include<bits/stdc++.h>
using namespace std;
int mem[1005][1005],track[1005];
int wei[100],val[100];
int n,bag,i;
int knap(int x,int cap){
    if(x==n || cap<=0) return 0;
    //if(wei[x]>cap) return 0;
    if (mem[x][cap]) return mem[x][cap];
    mem[x][cap] = knap(x+1,cap);
    if(cap>=wei[x])
    mem[x][cap] = max(mem[x][cap], val[x] + knap(x+1,cap-wei[x]));
    return mem[x][cap];
}
int main(){
   scanf("%d",&bag);
   scanf("%d",&n);
   for(i=0;i<n;i++){
    scanf("%d%d",&wei[i],&val[i]); 
    }
    cout << knap(0,bag);

}
