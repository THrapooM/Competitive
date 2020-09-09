//https://codeforces.com/problemset/problem/633/C
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int x,i;
int main(){
    cin >> s1;
    x = s1.length();
    for(i=0;i<x;i++){
        s2[i] = s1[x-i-1];
    }
    for(i=0;i<x;i++){
        cout << s2[i];
    }
    //cout << s2;
}
