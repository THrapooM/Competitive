//https://www.codecube.in.th/task/11
#include<bits/stdc++.h>
using namespace std;
int crr[1005],mem[1005][1005],n,m,k,cnt,c1;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&mem[i][j]);
            if(!mem[i][j])
                cnt++;
        }
        crr[i] = cnt;
        cnt = 0;
    }
    //for(i=1;i<=n;i++) printf("%d",crr[i]);
    for(i=n; i>=1; i--)
    {
        crr[i] += crr[i+1];
        c1 = 0;
        if(crr[i]>=k)
        {
            for(j=1;j<=m;j++){
                c1+=mem[i][j];
              if(j>k) c1-=mem[i][j-k];
              if(c1<=crr[i+1] && j>=k) {printf("%d",i); return 0;}
            }
        }
    }
}
