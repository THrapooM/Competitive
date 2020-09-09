#include <bits/stdc++.h>
using namespace std;
int n,a[1001][1001],tra1,tra2;
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=2;i<=n+1;i++)
    {
        tra1=i-1;
        tra2=1;
//        printf("i=%d tra1=%d tra2=%d\n",i,tra1,tra2);
        while(tra1!=0)
        {
//            printf("tra1=%d tra2=%d\n",tra1,tra2);
            if(tra1==1 || tra2==1) a[tra1][tra2]=1;
            else a[tra1][tra2]=a[tra1-1][tra2]+a[tra1][tra2-1];
            tra1--;
            tra2++;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) if(i+j<n+2) printf("%d ",a[i][j]);
        printf("\n");
    }
}
