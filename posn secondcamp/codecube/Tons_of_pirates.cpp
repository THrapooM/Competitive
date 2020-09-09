#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int sli[maxn],x[100005],y[100005],tree[maxn];
bool arr[100005];
string s[] = {"sleep","eat","work","eat","work","eat"};
int check = 1;
int cnt = 0;
unordered_map<int,int>mymap;
int N,Q,i,t,t2,t3,idx,tmp;
void update(int idx,int val){
    while(idx <= check){
        tree[idx] += val;
        idx += idx&-idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx >= 1){
        sum += tree[idx];
        idx -= idx&-idx;
    }
    return sum;
}
int main(){
    scanf("%d%d",&N,&Q);
    for(i = 0 ; i < Q ; i++){
        scanf("%d",&arr[i]);
        if(arr[i]==1){
            scanf("%d%d",&x[i],&y[i]);
            sli[cnt++] = x[i];
            sli[cnt++] = ++y[i];
        }
        else{
            scanf("%d",&x[i]);
            sli[cnt++] = x[i];
        }
    }
    sort(sli,sli+cnt);
    for(i = 0 ; i < cnt ; i++) if(mymap.find(sli[i])==mymap.end()) mymap[sli[i]] = check++;
    for(i = 0 ; i < Q ; i++){
        if(arr[i]){
            update(mymap[x[i]],1);
            update(mymap[y[i]],-1);
        }
        else {
            tmp = query(mymap[x[i]]);
            cout << s[tmp%6] << endl;
        }
    }
    

}