#include<bits/stdc++.h>
using namespace std;
vector<int>from[200005];
int mem[200005];
int N,K,T,i;
struct axis{
    int nxt,mi;
}t;
queue<axis>q;
int maxx = -1e9,minn =1e9,t1,t2;
int main(){
    scanf("%d%d%d",&N,&K,&T);
    for(i=0;i<K;i++){
        scanf("%d%d",&t1,&t2);
        from[t1].push_back(t2);
    }
    fill(&mem[0],&mem[200004],1e9);
    mem[0] = 0;
    q.push({0,0});
    while(!q.empty()){
        t = q.front(); q.pop();
        if(t.nxt==N) {minn=t.mi; break;}
        if(t.mi==T) maxx= max(maxx,t.nxt);
        for(i=0;i<from[t.nxt].size();i++){
            if(mem[from[t.nxt][i]]>mem[t.nxt]+1) 
            {
            mem[from[t.nxt][i]]=mem[t.nxt]+1;
            q.push({from[t.nxt][i],mem[t.nxt]+1});
            }
         }
         if(mem[t.nxt+1]>mem[t.nxt]+1)
         {
          mem[t.nxt+1]=mem[t.nxt]+1;
          q.push({t.nxt+1,mem[t.nxt]+1});
         }
        }
        //cout << 1;
      //  cout << minn << " " << maxx;
    if(minn>T){
        printf("%d\n",minn);
        printf("0 %d",maxx);
    }
    else if(minn<=T){
        printf("%d\n",minn);
        printf("1");
    }
}

