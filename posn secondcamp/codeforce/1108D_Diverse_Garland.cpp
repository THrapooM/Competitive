#include<bits/stdc++.h>
using namespace std;
int N,ans,i;
string s;
char c[] = "RGB";
int main(){
    scanf("%d",&N);
    cin >> s;
    for(i = 1 ; i <= s.length() ; i++){
        if(s[i]==s[i-1]){
            ans++;
            for(int j = 0 ; j < 3 ; j++){
                if(s[i-1]!=c[j] && s[i+1]!=c[j])
                    s[i] = c[j];
            }
        }
    }
    printf("%d\n",ans);
    cout << s;   
}