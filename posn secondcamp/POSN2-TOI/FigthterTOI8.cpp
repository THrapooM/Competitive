#include<bits/stdc++.h>
using namespace std;
int n,i,pow1,pow2,cnt1,cnt2,t1;
int main(){
    scanf("%d",&n);
    pow1 = pow2 = n;
    for(i=1;i<=n*2;i++){
            scanf("%d",&t1);
            if(t1%2==0){
                cnt2++;
                cnt1 = 0;
                if(cnt2>=3) pow2 -= 3;
                else pow2 -= 1;
                if(pow2<=0){
                    printf("0\n%d",t1);
                    return 0;
                }
            }
            else if(t1%2==1){
                cnt1++;
                cnt2 = 0;
                if(cnt1>=3) pow1 -= 3;
                else pow1 -= 1;
                if(pow1<=0){
                    printf("1\n%d",t1);
                    return 0;
                }
            }
    }
}