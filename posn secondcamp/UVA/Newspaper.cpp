//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2315
#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>m;
char c;
int test,x,line,j,i,n;
double val;
string s;
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf(" %c%d",&c,&x);
            m[c] = x;
        }
        scanf("%d",&line);
        for(i=0;i<=line;i++){
            getline(cin,s);
            for(j=0;j<s.length();j++){
                if(m[s[j]]) {val += m[s[j]];
               // printf("%c = %d\n",s[j],m[s[j]]);
                }
            }
        }
        printf("%.2lf$\n",val/(float)100);
        m.clear();
        val = 0;
    }
}