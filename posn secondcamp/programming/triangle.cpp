//https://programming.in.th/task/rev2_problem.php?pid=1070
#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[100005];
int main(){
    scanf("%d",&n);
   for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n<3) {printf("no"); return 0;}
    sort(a,a+n);
    if(a[0]+a[1]<=a[n-1]) printf("yes");
    else printf("no");

}
