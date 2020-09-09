#include<bits/stdc++.h>
using namespace std;
int K,N,rad,mindist,i,j,t2;
struct axis{
    int x,y;
}t,a[100005];
int dis(int cx,int cy,int tx,int ty){
    double pyta,x,y;
    x = abs(cx-tx);
    y = abs(cy-ty);
    pyta = sqrt(x*x + y*y);
    return pyta-rad*2;
}
int main(){
    scanf("%d",&K);
    while(K--){
        bool found = false;
        int minn,closest=0,tmp;
        scanf("%d%d%d",&N,&rad,&mindist);
        for(i = 0 ; i < N ; i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(i = 0 ; i < N-1 ; i++){
            minn = 1e9;
            for(j = i+1 ; j < N ; j++){
                closest = dis(a[i].x,a[i].y,a[j].x,a[j].y);
                if(closest > mindist){
                        if(closest < minn){
                            minn = closest;
                            t2 = j;
                        }
                }
                else found = true;
                if(found) break;
            }
            t = a[t2];
            a[t2] = a[i+1];
            a[i+1] = t;
            if(found) break;
        }
        if(found) printf("N\n");
        else printf("Y\n");
    }
}