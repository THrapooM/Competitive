#include<bits/stdc++.h>
using namespace std;
int i,n,t1,t2,m,ans;
struct axis{
    int x,y;
    bool operator < (axis k) const{
    return k.y > y;
    }
}t;
vector<axis>v;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&t1,&t2);
        v.push_back({t1,t2});
    }
    sort(v.begin(),v.end());
    m=v.size();
    t1=0;
    for(i=0;i<m;i++)
        if(v[i].x>t1)
            ans++,t1=v[i].y;
    cout << ans;
}
