#include<bits/stdc++.h>
using namespace std;
int i,j,k,area[505][505],lo1,lo2,x,n,m,t,minn,z,o;
bool found;
int main(){
    for(x=0;x<2;x++){
    scanf("%d%d",&n,&m);
    minn = min(n,m);
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&lo1,&lo2);
        area[lo1][lo2] = 1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            area[i][j]  += area[i-1][j] + area[i][j-1] - area[i-1][j-1];
        }
    }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d ",area[i][j]);
            }
            printf("\n");
        }
    for(i=minn-1;i>=0;i--){
        for(j=0;j+i<m;j++){
            for(k=0;k+i<n;k++){
                z = area[k+i][j+i]-area[k+i][j-1]-area[k-1][j+i]+area[k-1][j-1];
                o = area[k+i-1][j+i-1]-area[k+i-1][j]-area[k][j+i-1]+area[k][j];
                //printf("i = %d j = %d k = %d z = %d m = %d\n",i,j,k);
                if(z-o==0) {found = true; break;}
            }
            if(found) break;
        }
        if(found) break;
    }
    printf("%d\n",i+1);
    found = false;
    memset(area,0,sizeof(area));
    }
}