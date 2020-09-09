//https://codeforces.com/problemset/problem/2/A
#include<bits/stdc++.h>
using namespace std;
map<string,int>m,k;
struct cr{
    string name;
    int x;
};
vector<cr>v;
string s,s2;
int val;
int n,i,j,maxx=-1e9;
int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s >>val;
        m[s] += val;
        v.push_back({s,val});
    }
    for(auto i:m){
      maxx = max(i.second,maxx);
    }
    for(j=0;j<v.size();j++){
        if(m[v[j].name]==maxx){
         k[v[j].name]+= v[j].x;
         if(k[v[j].name]>=maxx) {cout << v[j].name ; return 0;}
         }
        }
    }

