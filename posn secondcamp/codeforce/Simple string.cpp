#include<bits/stdc++.h>
using namespace std;
string s;
int i;
int main(){
    cin >> s;
    for(i=1;i<=s.length();i++){
            if(s[i]==s[i-1])
            for(s[i]='a';s[i]==s[i-1]||s[i]==s[i+1];s[i]++);
    }
    cout << s;
}
