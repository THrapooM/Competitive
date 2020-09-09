#include<bits/stdc++.h>
using namespace std;
int N,Q,limit=1,t1,t2,temp;
int tree[1200000];
char c;
void update(int idx,int val){
        idx += limit;
        tree[idx] = val;
        while(idx>=1){
            idx/=2;
            tree[idx] = max(tree[idx*2],tree[idx*2+1]);
        }
}
int findmax(int l,int r){
    l += limit;
    r += limit;
    int ans = -1e9;
    while(l<=r){
        if(l%2==1) ans = max(tree[l++],ans);
        if(r%2==0) ans = max(tree[r--],ans);
        l/=2,r/=2;
    }
    return ans;
}
int main(){
    scanf("%d%d",&N,&Q);
    while(limit<=N) limit*=2;
    while(Q--){
        scanf(" %c%d%d",&c,&t1,&t2);                
        if(c=='U') {update(t1,t2); continue;} 
        else temp = findmax(t1,t2);
        printf("%d\n",temp);
    }
}