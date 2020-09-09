#include<bits/stdc++.h>
using namespace std;
int N,i,j,maxx=-1e9,k;
unordered_map<string,int>m;s
string s,x;
int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&k);
        cin >> s;
        for(j=0;j<s.length()-k+1;j++){
            m[s.substr(j,k)]++;
            if(maxx<m[s.substr(j,k)]){
                maxx = m[s.substr(j,k)];
                x = s.substr(j,k);
            }
        }
        cout << x;
        maxx = -1e9;
        m.clear();
    }
}