#include<bits/stdc++.h>
using namespace std;
int N,M,i,str[200005],sear[200005],p[200005],cnt3,mem[200005],j,primee[200005],t1,cor[200005];
void kmppreprocess(){
    int i = 0,idx = -1;
    p[0] = -1;
    while(i < M){
        while(idx>=0 && sear[i]!=sear[idx]) idx = p[idx];
        i++,idx++,p[i] = idx;
    }
}
void kmp(){
    int i = 0,idx = 0,cnt=0,cnt2=M;
    while(i < N){
        while(idx >= 0 && mem[i]!=sear[idx]) idx = p[idx];
        	if(N-i>=M-idx){
                if(str[i]%cor[idx]==0) if(idx==M) cnt3++; 
            }
            i++,idx++;
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(i =2 ; i <= 100 ; i++){
        bool prime = true;
        for(j = 2 ; j*j <= i ; j++){
            if(i%j==0){
                prime = false;
                break;
            }
        }
        if(prime) primee[i] = true;
    }
    for(i = 0 ; i < N ; i++){
        scanf("%d",&str[i]);
        mem[i] = 2;
    }                   
    for(i = 0 ; i < M ; i++){
        scanf("%d",&cor[i]);
        if(primee[cor[i]] || cor[i]==1) sear[i] = 2;
    }
    kmppreprocess();
    kmp();
    printf("%d",cnt3);
}