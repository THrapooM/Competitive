#include <bits/stdc++.h>
using namespace std;
int N,mem[1005][1005],t1,t2,t3,easy[1005],ma;
bool check[1005];
struct node{
    int x,y,val;
    bool operator <(node a) const{
        if(a.x == x) return a.y > y;
        else return a.x > x;
    }
};
vector<node>v;
int chase(int x,int y){
    if(!mem[x][y])
    {
        int i;
        if(x < N)
        {
            for(i = x;i < N;i++)
            {
                if(!check[i])
                {
                    check[i] = true;
                    mem[x][y] = max(mem[x][y],chase(v[i].y,y)+v[i].val);
                    check[i] = false;
                }
                mem[x][y] = max(mem[x][y],chase(x+1,y));
            }
        }
        if(y < N)
        {
            for(i = y;i < N;i++)
            {
                if(!check[i])
                {
                    check[i] = true;
                    mem[x][y] = max(mem[x][y],chase(x,v[i].y)+v[i].val);
                    check[i] = false;
                }
                mem[x][y] = max(mem[x][y],chase(x,y+1));
            }
        }
        printf("  at %d %d = %d\n",x,y,mem[x][y]);
    }
    return mem[x][y];
}
int main(){
    int i,j;
    scanf("%d",&N);
    for(i = 0;i < N;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        v.push_back({t1,t2,t3});
    }
    sort(v.begin(),v.end());
    for(i = 0;i < N;i++) easy[i] = v[i].x;
    for(i = 0;i < N;i++) printf("%d %d %d\n",v[i].x,v[i].y,v[i].val);
    for(i = 0;i < N;i++) t1 = v[i].y,v[i].y = lower_bound(&easy[i+1],&easy[N],t1)-easy;
    for(i = 0;i < N;i++) printf("%d to %d\n",i,v[i].y);
    printf("%d",chase(0,0));
}