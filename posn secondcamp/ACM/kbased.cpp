#include<bits/stdc++.h>
using namespace std;
    int n,k,i;

int kbased(int i,int bzero){
        if(i==n) return 1;
        else{
            int cnt = (k-1)*kbased(i+1,0);
            if(bzero==0) cnt += kbased(i+1,1);
            return cnt;
        }
}
int main(){
    cin >> n >> k;
    cout << kbased(0,1);
    return 0;
}
