#include<bits/stdc++.h>
using namespace std;
int Q,p[1000005],n,m;
string s1,s2;
void kmppreprocess(){
    int i = 0,idx = -1;
    p[0] = -1;
    while(i<m){
        while(idx >= 0 && s2[i]!=s2[idx]) idx = p[idx];
        i++,idx++,p[i] = idx;
    }
}
void kmp(){
    int i = 0,idx = 0;
    while(){

    }
}
int main(){
    scanf("%d",&Q);
    while(Q--){
        cin >> s1;
        n = s1.length();
        cin >> s2;
        m = s2.length();
        kmppreprocess();
        kmp();
    }
}