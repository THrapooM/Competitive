#include<bits/stdc++.h>
using namespace std;
int n,m,i,k,x,length[1005],j,t,high = -1e9;
int mem[1005],maxx=-1e9,track[1005];
stack<int>st;
struct axis{
    int x,y,i;
    bool operator <(axis t) const{
    if(x!=t.x) return t.x > x;
   // return y > t.y;

    }
};
vector<axis>v;
int cnt;
int main(){
   while(scanf("%d%d",&n,&m),n && m) v.push_back({n,m,++cnt});
    sort(v.begin(),v.end());
    x = v.size();
    // for(i=0;i<x;i++){
    //     printf("%d %d %d\n",v[i].x,v[i].y,v[i].i);
    // }

    for(i=0;i<x;i++){
        length[i] = 1;
        for(j=0;j<i;j++){
         if(v[i].y<v[j].y && v[i].x > v[j].x){
             t = length[j]+1;
         if(t>length[i]) length[i] = t,track[i] = j; 
         }
        }
    }
    for(i=0;i<x;i++){
        if(high < length[i]){
            high = length[i];
            t = i;
        }
    }
    //for (i = 0; i < x; i++) printf("track[%d] = %d\n",i,track[i]);
   // return 0;
    printf("%d\n",high);
    for(i=t;i!=0;i = track[i]) st.push(v[i].i);
    while(!st.empty()){
        printf("%d\n",st.top());
        st.pop();
    }
}
