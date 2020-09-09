#include<bits/stdc++.h>
using namespace std;
int V,st,en,E,i,t1,t2,t3,j,tmp,minn = 1e9;
struct way{                                                                                                                
    int x,val;
}t;
vector<way>v[2005],mem[2005];
struct axis{
    int x,val,cpath;
    bool operator < (axis k) const{
        if( t.val == val ) return k.cpath < cpath;
        return k.val < val;
    }
}K;
bool flag;
priority_queue<axis>heap;
// void check(){
//     for(int i = 0 ; i < mem[en].size() ; i++){
//         printf("mem[%d][%d].x = %d mem[%d][%d].val = %d\n",en,i,mem[en][i].x,en,i,mem[en][i].val);
//     }
// }
int main(){
    scanf("%d%d%d%d",&V,&st,&en,&E);
    for(i = 0 ; i < E ; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
    }
    heap.push({st,0,0});
    while(!heap.empty()){
        K = heap.top(); heap.pop();
        for(i = 0 ; i < v[K.x].size() ; i++){
            int tx = v[K.x][i].x;
            int tval = v[K.x][i].val + K.val;
            int tpath = K.cpath;
            flag = true;
            for(j = 0 ; j < mem[tx].size() ; j++){
                if(mem[tx][j].x < tval && mem[tx][j].val < tpath){
                    flag = false;
                    break;
                }
            }
            if(flag){
                heap.push({tx,tval,K.cpath+1});
                mem[tx].push_back({tval,K.cpath+1});
            }
        }
    }
    int Q;
    scanf("%d",&Q);
    //check();
    for(i = 0 ; i < Q ; i++){
        scanf("%d",&tmp);
        minn = 1e9;
        for(j = 0 ; j < mem[en].size() ; j++){
            minn = min(minn , mem[en][j].x + (mem[en][j].val-1)*tmp);
        }
        printf("%d ",minn);
    }

}