#include<bits/stdc++.h>
using namespace std;
string s;
int low,high,i;
int main(){
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i]>='a' && s[i] <='z') low++;
        else high++;
    }
    if(low>=high){
        for(i = 0 ; i < s.length() ; i++){
            if(s[i]>='A' && s[i]<='Z') s[i] += 32;
            printf("%c",s[i]);
        }
    }
    else {
        for(i = 0 ; i < s.length() ; i++){
            if(s[i]>='a' && s[i] <='z') s[i] -= 32;
            printf("%c",s[i]);
        }
    }
}