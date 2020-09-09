#include<bits/stdc++.h>
using namespace std;
int power,a[10],i,minn = -1e9,temp,j;
bool used[10];
struct axis{
    int idx,val;
    bool operator < (axis k) const {
        if(val!=k.val) return k.val > val;
        return k.idx < idx;
    }
}t;
vector <axis>v;
int main(){
    scanf("%d",&power);
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
        if(i>0) v.push_back({i,a[i]});
    }
   sort(v.begin(),v.end());
//    for(i=0;i<v.size();i++){
//         printf("%d %d\n",v[i].idx,v[i].val);
//    }
   if(v[0].val > power) {printf("-1"); return 0;}
    for(i=0;i<v.size();i++){
        temp = power/v[i].val;
        if(temp==0) continue;
        for(j=0;j<temp;j++){
            printf("%d",v[i].idx);
        }
        power -= v[i].val*temp;
    }
}