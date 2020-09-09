//https://www.codecube.in.th/task/174
#include<bits/stdc++.h>
using namespace std;
int N,Q,mem[1005][1005],t1,t2,j,mx,my,val[1005][1005];
long long factt[100005],i,tmp;
struct axis{
    int f,s;
}t;
vector<axis>v;
int main(){

    factt[0] =1;
    factt[1] = 1;
    for(i=1;i<=100000;i++){
        factt[i] = i*factt[i-1];
        factt[i] %= 1000000007;
    }
    scanf("%d%d",&N,&Q);
    for(i = 1 ; ; i <= 1000 ; i++){
        for(j = 1 ; j <= 1000 ; j++){
            mem[i]][j] = (factt[i+j-2])/(factt[i-1]*factt[j-1]);
        }
    }
    for(i = 1 ; i <= N ; i++){
        scanf("%d%d",&t1,&t2);
        val[t1][t2] = mem[]
    }
    for(i = 1 ; i <= Q ; i++){
        scanf("%d%d",&t1,&t2);
        v.push_back({t1,t2});
        mx = max(mx,t1);
        my = max(my,t2);
    }
    for(i = 1 ; i <= my ; i++){
        for(j = 1 ; j <= mx ; j++){
            val[i][j] = (mem[i-1][j] + mem[i][j-1] - mem[i-1][j-1])%1000000007;
        }
    }
    for(i = 1 ; i <=my ; i++){
        for(j =1 ; j <= mx ; j++){
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
    for(i = 1 ; i <= my ; i++){
        for(j = 1 ; j <= mx ; j++){
            printf("%d ",val[i][j]);
        }
        printf("\n");
    }
    for(i = 0 ; i < v.size() ; i++){
        tmp = mem[v[i].f][v[i].s] - (val[v[i].f][v[i].s] - val[v[i].f-1][v[i].s] - val[v[i].f][v[i].s-1] + val[v[i].f-1][v[i].s-1]);
        printf("%lld\n",tmp);
    }

    
}
