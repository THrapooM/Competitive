//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=257
#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,pos;
}t;
queue<axis>q;
vector<int>from[15];
vector<int>swit[15];
int main(){
    while(scanf("%d%d%d",&r,&d,&s)){
        for(i=1;i<=d;i++){
            scanf("%d%d",&t1,&t2);
            from[t1].push_back(t2);
            from[t2].push_back(t1);
        }
        for(i=1;i<=s;i++){
            scanf("%d%d",&t3,&t4);
            swit[t3].push_back(t4);
        }
        q.push({1<<1,1});
        while(!q.empty()){
            t = q.front(); q.pop();
            for(i=1;i<swit[t.i].size();i++){
                 int y = 1 << swit[t.i][i];
                 if(t.pos!=y &&!mem)


            }
            for(i=1;i<from[t.i].size();i++){
                int y = form[t.i][i];

            }
        }
}
}
