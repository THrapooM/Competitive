//https://www.proprog.tk/tasks/toi9_spaceship/descs/284
#include<bits/stdc++.h>
using namespace std;
int i,shop,sx,sy,sz,ex,ey,ez,vx,vy,vz,dis[15][15],N,j,minn=1e9;
struct axis{
    int x,y,z,pos,val,visit;
};
vector<axis>val,sinka;
int square(int x){
    return x*x;
}
queue<axis>q;
int main(){
    scanf("%d",&N);
    scanf("%d%d%d",&sx,&sy,&sz);
    val.push_back({sx,sy,sz,0,0,0});
    sinka.push_back({0,0,0,0,0,0});
    scanf("%d",&shop);
    for(i=0;i<shop;i++){
        scanf("%d%d%d",&ex,&ey,&ez);
        scanf("%d%d%d",&vx,&vy,&vz);
        val.push_back({ex,ey,ez});
        sinka.push_back({vx,vy,vz}); 
    }
    for(i=0;i<val.size();i++){
        for(j=i+1;j<val.size();j++){
                dis[j][i] = dis[i][j] = square(val[j].x-val[i].x)+square(val[j].y-val[i].y)+square(val[j].z-val[i].z);
         }
    }
    // for(i=0;i<shop;i++){
    //     for(j=0;j<shop;j++){
    //         if(dis[i][j])
    //         printf("dis[%d][%d] = %d ",i,j,dis[i][j]);
    //     }
    //     printf("\n");
    // }
    q.push({0,0,0,0,0,1<<0});
    while(!q.empty()){
        axis t = q.front(); q.pop();
        if(t.x>=N&&t.y>=N&&t.z>=N){
             minn = min(t.val,minn);
             continue; 
        }
        for(i=1;i<=shop;i++){
            if((t.visit&(1<<i))) continue;
            int tx = t.x+sinka[i].x;
            int ty = t.y+sinka[i].y;
            int tz = t.z+sinka[i].z;
            q.push({tx,ty,tz,i,dis[t.pos][i]+t.val,t.visit|1<<i});
           // cout << t.val << endl;
      }
    }
    cout << minn;

}