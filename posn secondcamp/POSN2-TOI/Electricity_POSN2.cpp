    #include<bits/stdc++.h>
    using namespace std;
    struct axis{
        int x,val;
        bool operator < (axis k) const {
            return k.val < val;
        }
    };
    int N,k,ans,i,a[500005],mem[500005];
    priority_queue<axis>pq;
    int main(){
        scanf("%d%d",&N,&k);
        for(i=1;i<=N;i++){
            scanf("%d",&a[i]);
        }
        pq.push({1,a[1]});
        //mem[1] = a[1];
        for(i=2;i<=N;i++){
            while(pq.top().x<i-k) pq.pop();
            mem[i] = a[i] + pq.top().val;
            pq.push({i,mem[i]});
            //cout << mem[i] << endl;
        }
        printf("%d",mem[N]);
    }