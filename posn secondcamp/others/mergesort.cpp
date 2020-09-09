#include<bits/stdc++.h>
using namespace std;
int i,N,arr[100005];
void merge(int arr[],int l,int mid,int r){
    int i,j,k=0;
    i = l,j = mid+1;
    int temp[100005];
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    for(i = 0 ; i < k ; i++) arr[l++] = temp[i];
}
void mergesort(int arr[],int l,int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,N-1);
    for(i = 0 ; i < N ; i++)
    printf("%d ",arr[i]);
}