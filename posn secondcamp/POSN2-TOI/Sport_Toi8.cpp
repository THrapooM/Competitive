#include<bits/stdc++.h>
using namespace std;
int n,l,w;
int a[3000005],cnt1,cnt2,t1;
void sport(int x,int y){
    if(x==t1-w||y==t1-l){
        for(int i=0;i<n;i++){
            if(cnt1==t1-w||cnt2==t1-l) break;
            if(a[i]) printf("W "),cnt1++;
            else printf("L "),cnt2++;

        }
        cnt1 = cnt2 = 0;
        printf("\n");
        return;
    }
    a[x+y] = 0;
    sport(x,y+1);
    a[x+y] = 1;
    sport(x+1,y);
}
int main(){
    scanf("%d%d%d",&n,&w,&l);
    t1 = n;
    n = (n*2)-1;
    sport(0,0);
}