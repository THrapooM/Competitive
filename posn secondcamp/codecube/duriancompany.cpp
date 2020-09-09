#include<bits/stdc++.h>
using namespace std;
int N,a[1000005];
int X,Y,MAX=0,check=-1e9;
int main()
{
    cin >> N;
    while(N--){
        cin >> X >> Y;
        MAX = max(max(MAX,X),Y);
        a[X]++;
        a[Y]--;
    }
    int i;
    for(i=1;i<MAX;i++){
     a[i] += a[i-1];
     check = max(a[i],check);
    }
//    for(i=1;i<MAX;i++){
//        printf("%d ",a[i]);
//    }
    cout << check;

}
