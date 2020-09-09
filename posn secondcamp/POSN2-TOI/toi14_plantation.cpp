#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int q,i,j;
int n,r,d;
struct Point{
    int x,y;
    bool operator < (Point k) const{
        if(k.x!=x) return k.x > x;
        return k.y > y;
    }
}point[100005];
double dis(int cx,int cy,int tx,int ty){
    double x,y,pyta;
    x = abs(cx-tx);
    y = abs(cy-ty);
    pyta = sqrt(x*x+y*y);
    return pyta;
}
double ans;
int main(){
    scanf("%d",&q);
    while (q--){
        double ans = inf;
        scanf("%d%d%d",&n,&r,&d);
        int mindist = d;
        for (i = 0; i < n; i++) scanf("%d%d",&point[i].x,&point[i].y);
        sort(point,point+n);
        for (i = 0; i < n-1; i++){
            for (j = i+1; j < n; j++){
                if (point[i].x + ans < point[j].x) break;
                double d = dis(point[i].x,point[i].y,point[j].x,point[j].y);
                if (d < ans) ans = d;
            }
        }
        if (ans - r*2 < mindist) printf("N\n");
        else printf("Y\n");
    }
}