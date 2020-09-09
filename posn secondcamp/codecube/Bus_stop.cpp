#include<bits/stdc++.h>
using namespace std;
int N,t1,i,x=1,lcm;
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&t1);
        if(t1>x) lcm = t1; 
        else lcm = x;
        while(1){
            if(lcm%x==0 && lcm%t1==0){
                break;
            }
            lcm++;
        }
        x = lcm;
    }
    printf("%d",x);

}