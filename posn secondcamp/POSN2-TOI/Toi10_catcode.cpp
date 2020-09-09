#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,x,che,K,len;
string s;
set<int>myset;
map<int,int>mem;
int main(){
    scanf("%d%d",&N,&M);
    for(i = 0 ; i < N ; i++){
        cin >> s;
        che = 0;
        for(j = 0 ; j < M ; j++){
            x = s[j]-'0';
            if(x) che |= 1 << (M-j-1);
        }
        mem[che] = i+1;
    }
    scanf("%d",&K);
    while(K--){
        scanf("%d",&len);
        bool found = false;
        cin >> s;
        che = 0;
        for(i = 0 ; i < len ; i++){
            if(i < M &&s[i]-'0'!=0) che |= 1 << (M-i-1);
            else if(i >= M) {
             che &= ~(1<<M-1);
             che = che << 1;
             che |= s[i]-'0';
            }
            if(mem[che] && i >= M-1) found = true,myset.insert(mem[che]);
          //  printf("i = %d che = %d\n",i,che);
        }
        if(!found) printf("OK\n");
        else { 
            for(auto i : myset) printf("%d ",i);
            printf("\n");
            myset.clear();
        }
    }
}