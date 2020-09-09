#include <bits/stdc++.h>
using namespace std;
int n = 3,a[20];
void f(int x){
    if (x == n){
        for (int i = 0; i < n; i++) cout <<a[i];
        cout<<endl;
    }
    else{
        a[x] = 0;
        f(x+1);
        a[x] = 1;
        f(x+1);
    }
}
int main(){
    f(0);
}
