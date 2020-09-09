#include<bits/stdc++.h>
using namespace std;
int x,y,i,j,ans;
int main(){
        while(cin >> x >> y){
            int st = min(x,y);
            int fi = max(x,y);
            int best =1;
            for(i=st;i<=fi;i++){
                    j=i;
                    ans = 1;
                    while(j!=1){
                            ans++;
                        if(j%2==0){
                            j = j/2;
                        }
                    else j = 3*j +1;
                    }
                    if(ans >best) best = ans;
            }
            printf("%d %d %d\n",x,y,best);
        }
}
