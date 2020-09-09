#include<bits/stdc++.h>
using namespace std;
int a[100005],N,i,t1,pos,l,r,mid,t2,b[100005],val = 1e9,tmp;
long long sum;
vector<int>ans;
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&b[i]);
        t1 = b[i];
        if(t1 >= a[pos]) a[++pos] = t1,tmp = t1;
        else {
            l = 1 ,r = pos;
            while(l <= r){
                mid = (l+r) >> 1;
                if(a[mid]>=t1){
                    t2 = mid;
                    r = mid -1;
                }
                else l = mid+1;
            }
            //printf("l = %d r = %d mid = %d\n",l,r,mid);
            a[t2] = t1;
        }
    }
    printf("%d ",pos);
    // for(i = 0 ; i <= N ; i++) printf("%d ",a[i]);
    // printf("\n\n");
    // for(i = ans.size()-1 ; i >=0 ; i--) printf("%d ",ans[i]);
    // printf("\n\n");
    for(i = ans.size()-1 ; i >=0 ; i--){
        if(ans[i]<=val) {
            val =ans[i];
            sum += val;
            //printf("%d %lld 1\n",i,sum);
        }
        else{
            val = a[i+1];
            sum += val;
           // printf("%d %lld 2\n",i,sum);
        }
    }
    //printf("\n");
    printf("%lld",sum);
    

}