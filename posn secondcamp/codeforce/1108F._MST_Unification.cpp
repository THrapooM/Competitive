#include<bits/stdc++.h>
using namespace std;
int V,E,i,t1,t2,t3,j,cnt,k,ans;
int h[200005],rnk[200005];
struct axis{
    int x,y,val;
    bool operator < (axis k) const{
        return k.val > val;
    }
}t;
int head(int x){
    if(h[x]==x) return x;
    return h[x] = head(h[x]);
}
bool Merge(int x,int y){
    int t1 = head(x);
    int t2 = head(y);
    if(t1==t2) return false;
    if(rnk[t1] < rnk[t2]) rnk[t2] += rnk[t1],h[t1] = t2;
    else rnk[t1] += rnk[t2],h[t2] = t1;
    return true;
}
vector<axis>vec;
int main(){
    scanf("%d%d",&V,&E);
    for(i = 1 ; i <= V ; i++) h[i] = i,rnk[i] = 1;
    for(i = 0 ; i < E ; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        vec.push_back({t1,t2,t3});
    }
    sort(vec.begin(),vec.end());
    for(i = 0 ; i < E ; ++i){
        j = i;
        while(j <= E && vec[i].val==vec[j].val) j++;
        cnt = j-i;
        for(int k = i ; k < j ; k++){
            if(head(vec[k].x)==head(vec[k].y)) cnt--;
        }
        for(int k = i ; k < j ; k++){
            cnt -= Merge(vec[k].x,vec[k].y);
        }
        ans += cnt;
        i = j-1;
    }
    printf("%d",ans);
}