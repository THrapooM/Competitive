#include<bits/stdc++.h>
using namespace std;
int x,y,N,i,j,t1,t2,t3,t4;
struct axis{
    int val,x,y;
    bool operator < (axis k) const{
        return k.val > val || (k.val==val && (k.x > x));
    }
};
struct axis2{
    int x,y;
}coor[4][1005];
map<int,vector<axis>>vec;
int main(){
    scanf("%d%d%d",&x,&y,&N);
    for(i = 1 ; i <= 4 ; i++){
        for(j = 1 ; j <= N ; j++){
            scanf("%d%d",&coor[i][j].x,&coor[i][j].y);
        }
    }
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= N ; j++){
            t1 = coor[1][i].x + coor[2][j].x;
            t2 = coor[1][i].y + coor[2][j].y;
            t3 = coor[3][i].x + coor[4][j].x;
            t4 = coor[3][i].x + coor[4][j].y;
            vec[t1].push_back({t2,i,j});
            nvec[t3].push_back({t4,i,j});
        }
    }
    sort(vec.begin(),vec.end());
    sort(nvec.begin(),nvec.end());

    
}