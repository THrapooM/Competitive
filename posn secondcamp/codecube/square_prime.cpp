#include<bits/stdc++.h>
using namespace std;
bool sq[1000005],check;
int i,j,mul,st,fi;
int main(){
    for(i=2;i<=1000;i++){
        mul = i*i;
        check = false;
        for(j=2;j<i;j++){
            if(i%j==0) check = true;
        }
        if(!check) sq[mul] = true;
    }
    check = false;
    scanf("%d%d",&st,&fi);
    for(i=st;i<=fi;i++){
        if(sq[i]) printf("%d ",i),check=true;
    }
    if(!check) printf("-1");

}