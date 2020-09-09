#include<bits/stdc++.h>
using namespace std;
int N;
long long mem[50][2];
long long flag(int stay ,int blue){
    if(stay==N) {
            if(blue==1)return 0;
            return 1;
    }
    if(mem[stay][blue]) return mem[stay][blue];
    long long count=0;
    if(blue!=1){
        count  += flag(stay+1,0);
        count  += flag(stay+1,1);
    }
    else count += flag(stay+1,0);
    return mem[stay][blue] = count;
}
int main()
{

      cin >> N;
      cout <<flag(1,0)*2;
    // bef==1 mean before 1 point is blue;

}
