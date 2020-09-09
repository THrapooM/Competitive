#include<bits/stdc++.h>
using namespace std;
int i,idx,p[5000005],N;
string s,s1;
void kmppreprocess(){
    i = 0,idx = -1; p[0] = -1;
    while(i < N){
        while(idx >= 0 && s[i]!=s[idx]) idx = p[idx];
        i++,idx++;
        p[i] = idx;
    }
}
int kmp(int x){
    int i = 1,idx = 0;
    while(i < N*2){
        while(idx >= 0 && s1[i]!=s[idx]) idx = p[idx];
        i++,idx++;
        if(idx==x){
            return i;
        }
    }
}
int main(){
    scanf("%d",&N);
    cin >> s;
    kmppreprocess();
    s1 = s+s;
    printf("%d",kmp(N)-N);
    

}