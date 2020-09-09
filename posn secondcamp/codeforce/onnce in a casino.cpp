#include<bits/stdc++.h>
using namespace std;
string s;
char a[10005],b[10005];
int x[10005],k[10005],i,j;
int main(){
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf(" %c",&a[i]);
            x[i] = a[i]-'0';
        }
        for(i=1;i<=n;i++){
            scanf(" %c",&b[i]);
            k[i] = b[i]-'0';
        }
//        for(i=0;i<n;i++){
//            printf("%d",x[i]);
//        }
//         for(i=0;i<n;i++){
//            printf("%d",k[i]);
//        }
        j = 1; i = 1;
        while(j!=n){
         if(x[j]!=k[j]){
                if(k[j]>x[j]){
                    for(z = 0;z<k[j]-x[j];z++){
                        cnt++;
                        v[j].push_back(1);
                    }
                }
                else if(x[j]<k[j]){
                    for(z = 0;z<x[j]-k[j];z++){
                        cnt++;
                        v[j].push_back(-1);
                    }
                }

         }
        }

}
