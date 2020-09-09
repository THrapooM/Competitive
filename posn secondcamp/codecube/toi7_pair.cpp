#include<bits/stdc++.h>
using namespace std;
struct axis{
    int x,y;
    bool operator < (axis k) const{
        return k.y > y;
    }
};
axis a[100005];
long long cnt;
void merge(axis a[],int l,int mid,int r){
        int i = l,j = mid+1,k = 0;
        int temp[100005];
        while(i <= mid && j <= r){
            if(a[i].x < a[j].x){
                 cnt += (long long)(a[i].x)*(j-mid-1);
             //printf("1 cnt = %lld %d %d %d\n",cnt,a[i].x,j,mid+1);
                temp[k++] = a[i++].x;
            }
            else {
                cnt += (long long)(a[j].x)*(mid-i+1);
            //printf("2 cnt = %lld %d %d %d\n",cnt,a[j].x,i,mid+1);
                temp[k++] = a[j++].x;
            }
        }
        while(i <= mid) cnt+=(long long)(a[i].x)*(j-mid-1),temp[k++] = a[i++].x;
        while(j <= r) temp[k++] = a[j++].x;
        for(i = 0 ; i < k ; i++) a[l++].x = temp[i];
}
void mergesort(axis a[],int l,int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main(){
    int N,i;
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a,a+N);
    // for(i = 0 ; i < N ; i++) printf("%d %d ",a[i].x,a[i].y);
    // printf("\n");
    mergesort(a,0,N-1);
    printf("%lld",cnt);
}