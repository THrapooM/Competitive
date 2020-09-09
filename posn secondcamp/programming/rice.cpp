#include<bits/stdc++.h>
using namespace std;
priority_queue<float>pq;
deque<float>dq;
int main(){
    int n;
    int i;
    float a,b,c;
    float w;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%f%f",&a,&b);
        c = a/b;
        pq.push(c);
    }
    while(!pq.empty()){
        dq.push_front(pq.top());
        pq.pop();
    }
    int x;
    for(i=0;i<dq.size();i++){
        printf("%f",dq[i]);
    }

}


