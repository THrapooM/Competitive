#include<bits/stdc++.h>
using namespace std;
int n,i,score[5],sum,total,j;
int main(){
    scanf("%d",&total);
    for(i=0;i<5;i++){
        scanf("%d",&score[i]);
        sum += score[i];
    }
    if(sum==total){
        for(i=0;i<5;i++)
        printf("%d ",score[i]);
        return 0;
    }
    for(i=0;i<5;i++){
        if(sum-score[i]==total){
            for(j=0;j<5;j++){
                if(j!=i) printf("%d ",score[j]);
                else printf("0 ");
            }
            return 0;
        }
    }
    printf("-1");
}