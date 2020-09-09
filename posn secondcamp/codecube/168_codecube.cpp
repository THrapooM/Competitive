#include<bits/stdc++.h>
using namespace std;
int N,x,i,low = 1e9;
string s;
int mem[10][10];
// c o d e c u b e
// 0 1 2 3 4 5 6 7
int main(){
    cin >> s;
    x = s.length();
    for(i = 0 ; i < x ; i++){
        if(s[i]=='c'){
            mem[0][0] = i+1;
            if(mem[3][3]) mem[4][4] = i+1,mem[4][0] = mem[3][0];
        }
        else if(s[i]=='o'){
            if(mem[0][0]) mem[1][1] = i+1,mem[1][0] = mem[0][0];
        }
        else if(s[i]=='d'){
            if(mem[1][1]) mem[2][2] = i+1,mem[2][0] = mem[1][0];
        }
        else if(s[i]=='e'){
            if(mem[2][2]) mem[3][3] = i+1,mem[3][0] = mem[2][0];
            if(mem[6][6] && low > i+1 - mem[6][0]) mem[7][7] = i+1,low = i+1-mem[6][0],mem[7][0] = mem[6][0];
        }
        else if(s[i]=='u'){
            if(mem[4][4]) mem[5][5] = i+1,mem[5][0] = mem[4][0];
        }
        else if(s[i]=='b'){
            if(mem[5][5]) mem[6][6] = i+1,mem[6][0] = mem[5][0];
        }
    }
    if (!mem[7][7]) printf("-1");
    else printf("%d %d",mem[7][0],mem[7][7]);
    
}