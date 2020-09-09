#include<bits/stdc++.h>
using namespace std;
int N,i,arr[5000005],K,t,cnt;
vector<int>vec;
deque<int>deq;
int main(){
    scanf("%d%d",&N,&K);
    for(i = 1 ; i <= N ; i++) scanf("%d",&arr[i]);
    for(i = 1 ; i <= N ; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            vec.push_back(arr[i]);
    }
    if(!vec.size()) {printf("-1");return 0;}
    sort(vec.begin(),vec.end());
    //for(i = 0 ; i < vec.size() ; i++) printf("vec[%d] = %d\n",i,vec[i]);
    for(i = 0 ; i < vec.size() ; i++) if(vec[i]!=vec[i-1]) deq.push_back(vec[i]);  
    if(deq.size() >= K){
        while(!deq.empty()){
            t = deq.back(); deq.pop_back();
            printf("%d\n",t);
            cnt++;
            if(cnt==K) return 0;
        }
    }
    else{
        while(!deq.empty()){
            t = deq.front(); deq.pop_front();
            printf("%d\n",t);
        }
        return 0;
    }
}