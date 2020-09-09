#include<bits/stdc++.h>
using namespace std;
int a[105][10005];
struct node{
    int x,val;
    bool operator < (node t) const{
        return val < t.val;
    }
};
priority_queue <int> v;
int main(){
    int N,M,K;
    cin >> N >> M >> K;
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M ;j++)
            cin >> a[i][j];

    for (i = 1; i < N; i++){
        priority_queue <node> pq;
        for (j = 0; j <= K; j++)
            pq.push({j,a[i-1][j]});

        for (j = K+1;j < M; j++){
            pq.push({j,a[i-1][j]});
            while (pq.top().x < j-K) pq.pop();
            a[i][j] += pq.top().val;

        }
        if (i == N-1) for (j = 0; j < M; j++) v.push(a[i][j]);
    }
//    cout<<endl;
//    for (i = 0; i < N; i++){
//        for (j = 0; j < M; j++)
//            cout << a[i][j] << " ";
//        cout <<endl;
//    }
    cout << v.top();
}
