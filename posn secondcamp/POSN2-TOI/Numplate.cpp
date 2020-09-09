#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
string s,t,tmp,s1;
char z[12];
queue<string>q;
int k,N,j;
void f(int x,int y[]){
    for(int i=0;i<x;i++){
        swap(tmp[k],tmp[y[i]]);
        if(!m[tmp]){
            m[tmp] = m[t]+1;
            q.push(tmp);
        }
        tmp = t;
    }
}
int main(){
        int cse;
        m["0123"] = 1;
        q.push("0123");
        while(!q.empty()){
            t = q.front(); q.pop();
            tmp = t;
            for(k=0;k<4;k++){
                if(t[k]=='0'){
                    if(k==0||k==3){
                        int x[] = {1,2};
                        f(2,x);
                    }
                    else if(k==1|| k==2){
                        int x[] = {0,3};
                        f(2,x);
                      }
                    }
                }
            }
        m["012345678"] = 1;
        q.push("012345678");
        while(!q.empty()){
            t = q.front(); q.pop(); tmp = t;
            for(k=0;k<9;k++){
                if(t[k]=='0'){
                    if(k==0){
                        int x[] = {1,3};
                        f(2,x);
                    }
                    else if(k==1){
                        int x[] = {0,2,4};
                        f(3,x);
                    }
                    else if(k==2){
                        int x[] = {1,5};
                        f(2,x);
                    }
                    else if(k==3){
                        int x[] = {0,4,6};
                        f(3,x);
                    }
                    else if(k==4){
                        int x[] = {1,3,5,7};
                        f(4,x);
                    }
                    else if(k==5){
                        int x[] = {2,4,8};
                        f(3,x);
                    }
                    else if(k==6){
                        int x[] = {3,7};
                        f(2,x);
                     }
                    else if(k==7){
                        int x[] = {4,6,8};
                        f(3,x);
                    }
                    else if(k==8){
                        int x[] = {5,7};
                        f(2,x);
                    }
                }
            }
        }
         scanf("%d",&cse);
        while(cse--){
                scanf("%d",&N);
                // if(N==3){
                  for(j=0;j<N*N;j++){
                      scanf(" %c",&z[j]);
                  }
                  printf("%d\n",m[z]-1);
                   }
        }
                
