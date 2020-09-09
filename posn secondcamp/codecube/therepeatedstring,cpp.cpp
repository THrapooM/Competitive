//https://www.codecube.in.th/task/80
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>m;
string s;
int x,cnt,i,j,k;
int main(){
    for(k=0;k<5;k++){
        cin >> s;
        x = s.length();
        for(i=1;i<=x;i++){
            if(!(x%i)){
                while(j<s.length()){
                    m[s.substr(j,i)]++;
                    j+=i;
                }
                if(m[s.substr(0,i)]*i==x) cnt++;
            }   
            j = 0;
        }
        printf("%d\n",cnt);
        cnt = 0;
        m.clear();
    }
}