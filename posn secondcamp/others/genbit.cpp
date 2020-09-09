#include<bits/stdc++.h>
using namespace std;
char c[100];
int x,y,a,b;
void genbit(int x,int y){
    if(x==a&&y==b){
        printf("%s\n",c);
        return;
    }
    if(x<a){
          c[x+y]='0';
        genbit(x+1,y);
    }
    if(y<b){
        c[x+y]='1';
        genbit(x,y+1);
    }
}
int main(){

    scanf("%d%d",&a,&b);
    genbit(0,0);
}
