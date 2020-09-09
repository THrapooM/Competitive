#include<bits/stdc++.h>
using namespace std;
int beew[30],beeall[30];
int main(){
    beew[1]  = 2;
    beeall[1] = 4;
    int i;
    for(i=2;i<=24;i++){
        beeall[i] = beew[i-1] + beeall[i-1] +1;
        beew[i] = beeall[i-1];
    }
//    for(i=1;i<=24;i++){
//        cout << beew[i] <<" " << beeall[i] << endl;
//    }
    int n;
    while(1){
        cin >> n;
        if(n==-1) break;
        cout << beew[n] << " " << beeall[n] << endl;
    }

}
