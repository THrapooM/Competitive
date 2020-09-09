#include<bits/stdc++.h>
using namespace std;
int a[100005];
int high = -1e9,t;
int low = 1e9,cnt;
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        a[t]++;
        high = max(high,t);
        low = min(low,t);
    }
    while(high-low>k){
        if(!a[high]) high--;
       else if(!a[low]) low++;
        else{

            if(a[high]==a[low]){
                 //   cout << 1;
                cnt += a[high];
                a[high-1] += a[high];
                a[low+1] += a[low];
                a[high] =0;
                a[low] =0;
            }
            else if(a[high]>a[low]){
                //cout << 2;
                    cnt += a[low];
                    a[high] -= a[low];
                    a[high-1] += a[low];
                    a[low+1] += a[low];
                    a[low] = 0;
                    }
            else if(a[low]>a[high]){
                //cout << 3;
                    cnt += a[high];
                    a[low] -= a[high];
                    a[high-1] += a[high];
                    a[low+1] += a[high];
                    a[high] = 0;
            }

        }
    }
    printf("%d",cnt);
}
