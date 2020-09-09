#include<bits/stdc++.h>
using namespace std;
int n,q,t1,t2,i,E,cou,cnt;
long long val;
map<long long,int>mymap;
int main(){
    scanf("%d%d",&n,&q);
    while(n--){
        scanf("%d",&E);
        val = 0;
        for(i = 0 ; i< E-1;i++){
            scanf("%d%d",&t1,&t2);
            val += t1*t1 + t2*t2;
        }
        mymap[val]++;
    }
    while(q--){
        scanf("%d",&E);
        cnt = 0;
        val = 0;
        for(i = 0; i< E-1;i++){
            scanf("%d%d",&t1,&t2);
            val += t1*t1 + t2*t2;
        }
        cnt += mymap[val];
        printf("%d\n",cnt);
        cnt = 0;
    }
}