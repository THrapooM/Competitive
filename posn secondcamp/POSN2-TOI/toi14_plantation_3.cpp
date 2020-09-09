#include<bits/stdc++.h>
using namespace std;
int Q,N,r,mindist,i,t1,t2,dis;
struct axis{
    int x,y;
}point[100005],tmp[100005];
bool cmp1(axis a,axis b){
        return a.x <  b.x;
}
bool cmp2(axis a,axis b){
    return a.y < b.y;
}
long long dist(axis x,axis y){
    return 1ll*((x.x-y.x)*(x.x-y.x))+1ll*((x.y-y.y)*(x.y-y.y));
}
int solve(int l,int R){
    if(l>=R) return 1e9;
    int mid = (l+r) >> 1;
    long long d = min(solve(l,mid),solve(mid+1,R));
    int x = 0;
    for(int i = mid ; i >= l && point[mid].x - point[i].x < d ; i--) tmp[x++] = point[i];
    for(int i = mid+1 ; i <= R && point[i].x - point[mid].x < d ; i++) tmp[x++] = point[i];
    sort(tmp,tmp+x,cmp2);
    for(int i = 0 ; i < x-1 ; i++){
        for(int j = 1 ; j<= 3, i+j < x; j++){
            d = min(d,dist(tmp[i],tmp[j+i]));
        }
    }
    return d;
}
int closestpair(){
    sort(point+1,point+N+1,cmp1);
    return solve(1,N);
}
int main(){
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d",&N,&r,&mindist);
        for(i = 1 ; i <= N ; i++){
            scanf("%d%d",&t1,&t2);
            point[i].x = t1;
            point[i].y = t2;
        }
        double dis = 1e9;
    //   double dis = sqrt(closestpair());
        if(dis - 2*r < mindist) printf("N\n");
        else printf("Y\n");
    }
}