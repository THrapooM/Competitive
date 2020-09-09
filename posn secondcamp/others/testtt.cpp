// #include <bits/stdc++.h>
// using namespace std;
// int N,T,fw[1000005],t1,t2,t3,t4,_MAXW,_MAXH,ans,tmp;
// bool che;
// struct node{
//     int h,val;
// };
// vector<node>V[3000005];
// void update(int x,int val){
//     for(;x <= _MAXH;x += x&-x) fw[x] += val;
// }
// int find(int x){
//     if(x > _MAXH) return 0;
//     int ans = 0;
//     for(;x > 0;x -= x&-x) ans += fw[x];
//     return ans;
// }
// int main(){
//     scanf("%d%d",&N,&T);
//     fw[0] = 1e9;
//     for(int i = 0;i < N;i++)
//     {
//         scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
//         V[t1].push_back({t2,t4});
//         V[t1+t3].push_back({t2,-t4});
//         _MAXW = max(t1+t3,_MAXW);
//         _MAXH = max(t2,_MAXH);
//     }
//     for(int i = 1;i <= _MAXW;i++)
//     {
//         che = false;
//         for(int j = 0;j < V[i].size();j++) update(_MAXH-V[i][j].h+1,V[i][j].val) ,che = true;
//         if(che)
//         {
//             int bot1 = 1,top1 = _MAXH,mid1;
//             while(bot1 <= top1)
//             {
//                 mid1 = (bot1+top1)>>1;
//                 t1 = find(_MAXH-mid1+1);
//                 if(t1 > T) bot1 = mid1+1;
//                 else top1 = mid1-1;
//             }
// 			printf("1 l = %d r = %d mid = %d\n",bot1,top1,mid1);
//             int bot2 = 1,top2 = _MAXH,mid2;
//             while(bot2 <= top2)
//             {
//                 mid2 = (bot2+top2)>>1;
//                 t1 = find(_MAXH-mid2+1);
//                 if(t1 >= T) bot2 = mid2+1;
//                 else top2 = mid2-1;
//             }
// 			printf("1 l = %d r = %d mid = %d\n",bot2,top2,mid2);
//             if(!mid1) tmp = 0;
//             else tmp = bot2-bot1;
//         }
//         ans+= tmp;
//     }
//     printf("%d",ans);
// }
#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,n,k,tree[1000005];
int mx=0;
struct node{
    int x,h,val;
    bool operator < (node t) const{
        return t.x>x; }
};
vector <node> vord;
void update(int x,int y){
    while(x<=mx+5){
        tree[x]+=y;
        x+=x&-x;
    }
    return ;
}
int fnd(int x){
    int s=0;
    while(x>0)s+=tree[x],x-=x&-x;
    return s;
}

int right_bound(int l,int r){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        int t1=fnd(mid);
        if(t1==0)r=mid-1;
        else if(t1>=k)l=mid+1;
        else r=mid-1;
    }
    return l;
}

int left_bound(int l,int r){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        int t1=fnd(mid);
        if(t1==0)r=mid-1;
        else if(t1>k)l=mid+1;
        else r=mid-1;
    }
    return l;
}
int main(){
    long long int cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        vord.push_back({a,b,d});
        vord.push_back({a+c,b,-d});
        mx=max(mx,b);
    }
    sort(vord.begin(),vord.end());
    for(int j=0;j<vord.size();j++){
        update(1,vord[j].val);
        update(vord[j].h+1,-vord[j].val);
        if(vord[j].x==vord[j+1].x)continue;
//        for(int i=1;i<=mx;i++)printf("%d ",fnd(i));
        int t1=left_bound(1,mx),t2=right_bound(1,mx);
        cnt+=1ll*(t2-t1)*(vord[j+1].x-vord[j].x);
//        printf("\nx=%d t1=%d t2=%d cnt=%lld\n",vord[j].x,t1,t2,cnt);
    }
    printf("%lld",cnt);
}
