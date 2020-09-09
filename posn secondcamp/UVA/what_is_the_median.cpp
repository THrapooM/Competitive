#include<bits/stdc++.h>
using namespace std;
int high = 1;
long long a[10005],i,j,tmp,t1,t2;
bool found;
void check(){
    for(i=1;i<=high;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    while(scanf("%d",&tmp)!=EOF){
        high++;
        for(i=1;i<high;i++){
            if(a[i]<tmp) continue;
            else {
                found = true;
                t1 = a[i];
                a[i] = tmp;
                for(j=i+1;j<high;j++){
                t2 = a[j];
                a[j] = t1;
                t1 = t2;
            }
            }
            if(found)  break;
        }
        if(!found) a[high-1] = tmp;
        found = false;
        if(1&(high-1)) printf("%lld\n",a[(high-1)/2+1]);
        else printf("%lld\n",(a[(high-1)/2]+a[(high-1)/2+1])>>1);
    }
  //  check();
}