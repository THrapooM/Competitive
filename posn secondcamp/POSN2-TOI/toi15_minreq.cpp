#include<bits/stdc++.h>
using namespace std;
int N,M,Q,i,j,MINTIME;
int lift[15],old[15],T[15],first,last,val,sum,flag[20];
int stud[10000005],start[15];
bool pass;
bool check(int from,int to){
    int tmp = 0,val = 0,sum = 0,cnt = 1;
    bool mark = false;
    for(int i = 1 ; i <= N ; i++){
        if(mark) continue;
        if(flag[i]) continue;
        tmp = lift[i];
        for(int j = from ; j <= to ; j++){
            val = stud[j] - stud[j-1];
            sum += val;
            if(val > tmp) return 0;
            if(sum > tmp) cnt++,sum = val;
            //printf("val = %d cnt = %d sum = %d\n",val,cnt,sum);
        }
        if(cnt <= MINTIME && !mark){
            flag[i] = true;
            mark = true;
            return 1;
        }
        cnt = 1,sum = 0;
    }
    if(!mark) return 0;
    return 1;
}
int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for(i = 1 ; i <= N ; i++) scanf("%d",&lift[i]); sort(lift+1,lift+N+1);
    for(i = 1 ; i <= N ; i++) scanf("%d",&old[i]);  sort(old+1,old+N+1);
    for(i = 1 ; i <= N ; i++) lift[i] -= old[i];    sort(lift+1,lift+N+1);
    for(i = 1 ; i <= M ; i++) scanf("%d",&stud[i]),stud[i] += stud[i-1];
    for(i = 1 ; i <= Q ; i++) scanf("%d",&T[i]);
    for(i = 1 ; i <= Q ; i++){
        pass = true;
        MINTIME = T[i];
        for(j = 1 ; j <= N ; j++){
            scanf("%d",&start[j]);
            if(j != 1){
                if(!check(start[j-1],start[j]-1)) pass = false;
                if(!pass) break;
            }
        }
        if(pass) if(!check(start[N],M)) pass = false;
        if(!pass) printf("F\n");
        else printf("P\n");
        for(int j = 1 ; j <= N ; j++) flag[j] = false;
    }
}
