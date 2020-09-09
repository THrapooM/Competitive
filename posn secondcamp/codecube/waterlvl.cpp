#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],i,j,maxx,pos;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    i=0;
    while(i<n){
        if(a[i]<=a[i+1]) printf("%d ",a[i++]);
        else if(a[i]>a[i+1]){
            for(j=i+1;j<n;j++)
                if(maxx<a[j]){
                    maxx = a[j];
                    pos = j;
                }
                if(maxx>=a[i]){
                    maxx = a[i];
                    break;
                }

            for(;i<pos;i++){
                printf("%d ",maxx);
            }
            maxx=0;
            }
        }
}

