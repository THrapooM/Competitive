#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y,val;
}t,coor[15005];
int n,minn,k,i,j,t1,t2,cnt;
priority_queue<int>pq;
int main(){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d%d",&coor[i].x,&coor[i].y);
        coor[i].val = 1e9;
    }
    for(i=0;i<n-1;i++){
        minn = 1e9;
        for(j=i+1;j<n;j++){
            t1 = abs(coor[i].x-coor[j].x)+abs(coor[i].y-coor[j].y);
         //   cout << t1 << endl;
            if(t1<coor[j].val) coor[j].val = t1;
            if(coor[j].val<minn){
                minn = coor[j].val;
                t2 = j;
           }
        }
       // cout << minn;
        t = coor[t2];
        coor[t2] = coor[i+1];
        coor[i+1] = t;
        cnt += minn;
        pq.push(minn);
    }
    for(i=0;i<k-1;i++){
        cnt -= pq.top(); pq.pop();
    }
    cout << cnt;
}