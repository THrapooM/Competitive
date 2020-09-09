//https://programming.in.th/task/rev2_problem.php?pid=1077
#include<bits/stdc++.h>
using namespace std;
int maxx=-1e9,maxy=-1e9;
int a[1002][1002];
int n,m,t1,t2,t3,t4,pw,i,j,cx,cy,ccx,ccy;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
       scanf("%d%d",&t1,&t2);
        a[++t2][++t1] +=1;
        maxy = max(maxy,t2);
        maxx = max(maxx,t1);
    }
//    printf("%d %d\n",maxy,maxx);
    for(int i=1;i<=maxy;i++){
            for(int j=1;j<=maxx;j++){
                a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
    }
//    for(i=1;i<=maxy;i++){
//        for(j=1;j<=maxx;j++){
//                printf("%d ",a[i][j]);
//        }
//        printf("\n");
//    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&t3,&t4,&pw);
        t3++,t4++;
        if(t4-pw<1) cy = 1;
        else cy = t4-pw;
        if(t4+pw>maxy) ccy = maxy;
        else ccy = t4+pw;
        if(t3-pw<1) cx = 1;
        else cx = t3-pw;
        if(t3+pw>maxx) ccx = maxx;
        else ccx = t3+pw;
        printf("%d\n",a[ccy][ccx]-a[ccy][cx-1]-a[cy-1][ccx]+a[cy-1][cx-1]);
        //printf("%d %d %d %d %d %d\n",t3,t4,cx,cy,ccx,ccy);
    }

}
