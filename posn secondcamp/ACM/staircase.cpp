#include<bits/stdc++.h>
using namespace std;
    int N;
long long mem[505][505];
long long stair(int prev,int left){
    if(left==0) return 1;
    if(left<=prev) return 0;
    if(mem[prev][left]) return mem[prev][left];
    long long cnt = 0;
    for(int i=prev+1;i<=left;i++)
    {
        cnt += stair(i,left-i);
    }
        return mem[prev][left] = cnt;


}
int main(){
    cin >> N;
    cout << stair(0,N)-1;
}
