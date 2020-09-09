//https://programming.in.th/task/rev2_problem.php?pid=1019
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int minn,maxx,i,j,mlen,endd;
int table[205][205];
int main(){
    cin >> s1 >> s2;
    int x = s1.length();
    int y = s2.length();
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(s2[j-1]==s1[i-1]){
                table[i][j] = table[i-1][j-1]+1;
                if(table[i][j]>mlen){
                    mlen = table[i][j];
                    endd = i;}
            }
        }
    }
    cout << s1.substr(endd-mlen,mlen); return 0;
    }