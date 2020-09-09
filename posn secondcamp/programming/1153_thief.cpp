#include<bits/stdc++.h>
using namespace std;
int N,i,l,r,mid,nexxt[1005];
int mem[1005][1005];
struct axis{
    int x,y,val;
    bool operator < (axis k) const{
        return k.x > x || (k.x==x && k.y > y);
    }
}a[1005];
int thief(int pos1,int pos2){
    if(pos1>N+1 || pos2 > N+1) return 0;
    if(mem[pos1][pos2]) return mem[pos1][pos2];
    if(pos1 <= pos2) mem[pos1][pos2] = max(mem[pos1][pos2],thief(pos1+1,pos2));
    if(pos2 <= pos1) mem[pos1][pos2] = max(mem[pos1][pos2],thief(pos1,pos2+1));
    if(pos1 < pos2)  mem[pos1][pos2] = max(mem[pos1][pos2],thief(nexxt[pos1],pos2)+a[pos1].val);
    if(pos2 < pos1)  mem[pos1][pos2] = max(mem[pos1][pos2],thief(pos1,nexxt[pos2])+a[pos2].val);
    return mem[pos1][pos2];
}
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val);
    sort(a+1,a+N+1);
    for(i = 1 ; i <= N ; i++){
        l = 1,r = N;
        while(l <= r){    
            mid = (l+r) >> 1;
            if(a[i].y<=a[mid].x) r = mid-1;
            else l = mid+1;
        }
        nexxt[i] = l;
    }
    printf("%d",thief(1,1));
}