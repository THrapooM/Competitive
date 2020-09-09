#include<bits/stdc++.h>
using namespace std;
int cnt =0,n,m;
struct axis{
    int f,s,i;
    bool operator < (axis t) return {
        if(f!=t.f)return t.f>f;
    }
}
int f(int pos){

}
vector<axis>v;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        v.push_back({n,m,++cnt});
        sort(v.begin(),v.end());
        int x = v.size();
        f(1,0);
    
    }
}