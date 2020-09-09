//https://codeforces.com/problemset/problem/1133/F2
#include<bits/stdc++.h>
using namespace std;
int i,j;
vector<int>from[200005];
queue<int>q;
int main(){
    scanf("%d%d%d",&V,&E,&k);
    for(i=0;i<E;i++){
        scanf("%d%d",&t1,&t2);
        from(t1).push_back(t2);
        from(t2).push_back(t1);
        if((t1||t2)==1) x++;
    }
    if(x<k) {printf("N0") return 0;}
    q.push(1);
    while(!q.empty()){
            for(i=0;i<from[1].size();i++){

                    for(j=0;j<x;j++){
                        nq.push()
                            while(!nq.empty()){

                            }
                    }
            }
    }
}