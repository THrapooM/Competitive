#include<bits/stdc++.h>
using namespace std;
stack<char>st;
int N,i,j,t1,t2,siz;
bool k;
string s;
int main(){
    cin >> s;
    siz = s.length();
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d",&t1,&t2);
        t1--,t2--;
        if(t1<=t2)
        {
        for(j=t1;j<=t2;j++){
            st.push(s[j]);
            if(st.top()==')'){ st.pop();
                if(st.top()!='(' || st.empty()) {k = 1; break;}
                else st.pop();
            }
        }
        if(st.empty()&&k!=1) printf("yes\n");
        else printf("no\n");
        while(!st.empty()) st.pop();
        }
        if(t1>t2){
            for(j=t1;j<=siz+t2;j++){
                if(j<siz) st.push(s[j]);
                else if(j>=siz) st.push(s[j%siz]);
                if(st.top()==')'){ st.pop();
                if(st.top()!='(' || st.empty()) {k = 1; break;}
                else st.pop();
            }
            }
         if(st.empty()&&k!=1) printf("yes\n");
        else printf("no\n");
        while(!st.empty()) st.pop();
        }
        k = 0;
    }
}