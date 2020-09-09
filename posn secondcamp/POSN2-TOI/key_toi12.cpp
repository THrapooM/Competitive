//https://www.proprog.tk/tasks/toi12_key/descs/6791
#include<bits/stdc++.h>
using namespace std;
int x,y,k,j,n,i;
string s1,s2,s3;
bool visit[1005][1005];
bool mem[1005][1005];
int f(int x,int y){
    if(x==k&&y==j) return 1;
    if(visit[x][y]) return mem[x][y];
    visit[x][y] = true;
    if(s3[x+y]==s1[x]) mem[x][y] |= f(x+1,y);
    if(s3[x+y]==s2[y]) mem[x][y] |= f(x,y+1);
    return mem[x][y];
}
int main(){
    cin >> s1;
    k = s1.length();
    cin >> s2;
    j = s2.length();
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cin >> s3;
        if(f(0,0)) printf("Yes\n");
        else {printf("No\n");}
        memset(mem,0,sizeof(mem));
        memset(visit,0,sizeof(visit));
    }
}