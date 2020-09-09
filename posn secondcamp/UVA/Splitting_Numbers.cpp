//https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3084
#include<bits/stdc++.h>
using namespace std;
int a,b,i,n;
bool flag;
int main(){
    while(cin >> n){
        if(!n) return 0;
        i = a = b = 0; 
        flag = true;
        while(n!=0){
            if(1&n){
                if(flag){
                    a |= 1<<i;
                    b |= 0<<i;
                }
                else {
                    a|= 0<<i;
                    b|= 1<<i;
                }
                flag = !flag;
            }
            else{
                a|=0<<i;
                b|=0<<i;
            }
            i++;
            n = n>>1;
        }
        printf("%d %d\n",a,b);
    }
}