#include<bits/stdc++.h>
using namespace std;
int zero,one,tmp,N;
string s;
int i,j,k,a[5000005];
bool check;
int gcd(int x,int y){
    if(y!=0) return gcd(y,x%y);
    else return x;
}
int main(){
    scanf("%d",&N);
    cin >> s;
    for(i=0;i<N;i++){
        if(s[i]=='0') {zero++; a[i] = 0;}
        else {one++; a[i] = 1;}
    }
    tmp = gcd(zero,one);
   // cout << tmp ;
    if(tmp==1) {printf("%d",N);return 0;}
    else if(tmp==N) {printf("1"); return 0;}
    i = 1;
    while(i++){ 
          if((N%i)==0){
            check = 0;
            for(j=0;j<N;j+=i){
                for(k=j;k<N-i;k++){
                    if(a[k]!=a[k+i]){check = 1; break;}
                }
                if(check) break;
            }
            if(check) continue;
            else {printf("%d",i); return 0;}
          }                       
    }
   
}