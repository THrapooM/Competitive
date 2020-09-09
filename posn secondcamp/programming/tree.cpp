//https://programming.in.th/task/rev2_problem.php?pid=1151
#include<bits/stdc++.h>
using namespace std;
int N,t1,pos,l,r,mid,i,a[200005],t2;
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&t1);
        if(t1>a[pos]){
            a[++pos] = t1;
        }
        else{
                l=1; r = pos;
            while(l<=r){
                mid = (l+r)/2;
                if(a[mid]>=t1){
                    t2 = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            a[t2] = t1;
        }
    }
    printf("%d",pos);
}
