#include<bits/stdc++.h>
using namespace std;
struct axis{
    int multi,low,high;
}pos[200005];
int m,n,i;
int main(){
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&pos[i].multi,&pos[i].low,&pos[i].high);
    }
}