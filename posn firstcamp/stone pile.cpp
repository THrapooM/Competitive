#include<bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
    int n,i,j,high = 1e9,t = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    for (i = 1 << n-1; i > 0; i--){
        t = 0;
        for(j = 0; j < n; j++){
            if (i & 1 << j) t += a[j];
            else t -= a[j];
        }
        high = min(high,abs(t));
    }
    printf("%d",high);
}
