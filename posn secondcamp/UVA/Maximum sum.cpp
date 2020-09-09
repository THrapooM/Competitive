//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=44
#include<bits/stdc++.h>
using namespace std;
int N[105][105];
int i,j,k,n,t,maxx=-1e9,m ;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&N[i][j]);
            N[i][j]+=N[i][j-1];
        }
    }
    for(k=1; k<=m; k++)
    {
        for(j=k; j<=m; j++)
        {
            for(i=1; i<=n; i++)
            {
                t += N[i][j]-N[i][k-1];
                maxx = max(maxx,t);
                if(t<0)
                    t = 0;
            }
            t = 0;
        }
    }
    printf("%d",maxx);
}
//#include <bits/stdc++.h>
//using namespace std;
//int n,m,a[1005][1005],ma,f,t;
//int main(){
//    int i,j,k;
//    scanf("%d%d",&n,&m);
//    for(i=0;i<n;i++)
//        for(j=0;j<m;j++)
//        {
//            scanf("%d",&f);
//            a[i][j]=a[i][j-1]+f;
//        }
//    for(i=0;i<m;i++)
//        for(j=i;j<m;j++)
//        {
//            for(k=0;k<n;k++)
//            {
//                t+=a[k][j]-a[k][i-1];
//                if(t<0)t=0;
//                ma=max(ma,t);
//            }
//            t=0;
//        }
//        printf("%d",ma);
//}

