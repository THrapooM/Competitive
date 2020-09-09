#include<bits/stdc++.h>
using namespace std;
int N,i,t1,temp,nowmax,maxx[100005],Q,money,minn = 1e9;
struct axis{
    int val,idx;
    bool operator < (axis k) const{
        if(k.val!=val) return k.val > val;
        return k.idx < idx; 
    }
}qs[100005];
int bsearch(int val){
    int l = 1,r = N,mid;
    while(l <= r){
       mid = (l+r) >> 1;
       if(qs[mid].val == val) return mid;
       else if(qs[mid].val < val) l = mid+1;
       else r = mid-1;
    }
    return r;
}
int main(){
    scanf("%d%d",&N,&Q);
    for(i = 1; i <= N ; i++){
        scanf("%d",&t1);
        temp += t1;
        qs[i].val = temp;
        qs[i].idx = i;
        minn = min(temp,minn);
    }
    sort(qs+1,qs+N+1);
    for(i = 1; i <= N ; i++)
        maxx[i] = max(maxx[i-1],qs[i].idx);  
    while(Q--){
        scanf("%d",&money);
        if(money < minn) printf("0\n");
        else printf("%d\n",maxx[bsearch(money)]); 
    }
}