#include<bits/stdc++.h>
using namespace std;
string s;
int k,i,j,N,test,x;
int mem[200005];
stack<int>st;
int main(){
    cin >> s;
    scanf("%d",&N);
    x = s.length();
    s  = s+s;
    for(i=0;i<s.length();i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            k = st.top(); st.pop();
            mem[k] = i%x; 
           }
    }
    for(i=0;i<s.length();i++){
        printf("%d ",mem[i]);
    }
    
    // scanf("%d",&test);
    // for(i=0;i<test;i++){
    //     scanf("%d%d",&t1.&t2);

    // }
}