//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=632&page=show_problem&problem=3200
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>m;
int i,n,j,t1,cnt,t2,k,q;
int main(){
        scanf("%d",&q);
        while(q--){
           scanf("%d%d",&n,&k);
            for(i=0;i<n;i++){
                scanf("%d",&t1);
                m[t1]++;
            }
            for(j=0;j<k;j++){
                scanf("%d",&t2);
                if(m[t2]){
                    cnt++;
                    m[t2]--;
                }
            }
                printf("%d\n",n+k-(cnt*2));
                m.clear();
                cnt = 0;
        }
}
