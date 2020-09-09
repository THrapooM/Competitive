//https://www.codecube.in.th/task/175
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int N,m,i,maxx=-1e9;
string s;
int main(){
    scanf("%d%d",&N,&m);
    for(i=1;i<=N;i++){
        cin >> s;
      if(s[0]=='U' && s[1]=='R') a[i] = 1;
        a[i] += a[i-1];
    }
//    for(i=1;i<=N;i++){
//        printf("%d ",a[i]);
//    }
    for(i=m;i<=N;i++){
        maxx = max(maxx,a[i]-a[i-m]);
    }
    printf("%d",maxx);

}
