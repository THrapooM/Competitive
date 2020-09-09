#include<bits/stdc++.h>
using namespace std;
int arr[7] = {4,8,15,16,23,42};
int i,t[5];
int main(){ 
    for(i = 0 ; i < 4 ; i++){
        printf("? %d %d\n",i+1,i+2);
        scanf("%d",&t[i]);
    }
    while(1){
        bool found = 1;
        for(i = 0 ; i < 4 ; i++){
            if(arr[i]*arr[i+1]!=t[i]) found = false;
        }
        if(found) break;
        next_permutation(arr,arr+6);
    }

    printf("! ");
    for(i = 0 ; i < 6 ; i++) printf("%d ",arr[i]);
    return 0;
}