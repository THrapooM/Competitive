#include<bits/stdc++.h>
using namespace std;
vector<int>crr[2005];
priority_queue<int>heap;
int a[2005][2005];
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            crr[i+j].push_back(a[i][j]);
        }
    }
    int ans=0;
    for(i=(n-1)*2;i>0;i--){
        for(j=0;j<crr[i].size();j++){
            heap.push(crr[i][j]);
        }
        ans+=heap.top();
        heap.pop();
    }
    printf("%d",ans);
}
