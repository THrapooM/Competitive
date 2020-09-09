#include<bits/stdc++.h>
using namespace std;
string s;
int i,j,x,cnt;
char b[] = {"codecube"};
int main(){
    cin >> s;
    while(i < s.length()){
        if(j==8) j = 0;
        if(s[i]!=b[j]){
            x = j;
            while(x < 8){
                if(s[i]!=b[x]) x++;
                else break;
            }
            cnt += x-j;
            j = x;
        }
        else i++,j++;
    }
    if(i==s.length() && j!=8) cnt += 8-j;
    printf("%d",cnt);
}