#include<bits/stdc++.h>
using namespace std;
int mem[1005][1005],track[1005],t1;
int wei[100],val[100];
int n,bag,i;
int knap(int x,int cap){
    if(x==n || cap<=0) return 0;
    if (mem[x][cap]) return mem[x][cap];
    int t=0;
    for(int i=x;i<n;i++)
        if(cap>=wei[i]*8)
        {
            t=knap(i+1,cap-wei[i]*8)+val[i];
            if(t>mem[x][cap])
            {
                mem[x][cap]=t;
                track[x]=i+1;
            }
        }
    return mem[x][cap];

}
int main(){
   scanf("%d",&n);
   scanf("%d",&bag);
   for(i=0;i<n;i++){
    scanf("%d",&val[i]);
    }
    for (i = 0; i < n; i++) scanf("%d",&wei[i]);
    cout << knap(0,bag) << endl;
    // while(track[t1])
    // {
    //     t1=track[t1];
    //     printf("%d\n",t1);
    // }
}
