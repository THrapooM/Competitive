#include<bits/stdc++.h>
using namespace std;
int N,i;
string s;
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        cin >> s;
        if(s.length()<11) {printf("NO\n"); continue;}
        for(i = 0 ; i < s.length() ; i++){
            if(s[i]=='8') break;
        }
        if(s.length()-i < 11) printf("NO\n");
        else printf("YES\n");
    }
}