#include<bits/stdc++.h>
using namespace std;
int x,n,i,j,cnt;
int mem[505][505];
string s;
int cstr(int l,int r){
        //cout << "fsdfs";
        cout << cnt ;
        if(l==r) return 1;
        if(l>r) return 0;
        if(mem[l][r]) return mem[l][r];
        cnt = 0;
        cnt += cstr(l+1,r)+1;
        for(int i = l;i<=r;i++){
            if(s[l]==s[r]){
                cnt = min(cnt,cstr(i+1,r-1)+1);
            }
        }
        return mem[l][r] = cnt;
}
int main(){
    scanf("%d",&n);
    cin >> s;
    x  = s.length();
    memset(mem,1,sizeof(mem));
    cout << cstr(0,n-1);
    
}