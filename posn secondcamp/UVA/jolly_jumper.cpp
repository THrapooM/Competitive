//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
#include<bits/stdc++.h>
using namespace std;
bool mark[3005];
int a[3005],i,n,cnt;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(i>0) if(abs(a[i]-a[i-1])<n&&!mark[abs(a[i]-a[i-1])]){
                mark[abs(a[i]-a[i-1])] = true;
                cnt++;
            }
        }
            if(cnt==n-1) printf("Jolly\n");
            else printf("Not jolly\n");
            cnt = 0; 
            memset(mark,0,sizeof(mark));
            }
}