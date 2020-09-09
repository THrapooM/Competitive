//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3077
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,t1,t2,t3;
bitset<1000001>sche;
bool found;
int main(){
    while(cin >> n >> m){
        if(!n && !m) return 0;
        for(i=0;i<n;i++){
           if(found){scanf("%d%d",&t1,&t2); continue;}
           else{
               scanf("%d%d",&t1,&t2);
            for(j=t1+1;j<=t2;j++){
                if(sche.test(j)) found = true;
                else sche.set(j);
                if(found) break;
            } 
                }      
        }
        //if(found) {printf("CONFLICT\n");continue;}
        for(i=0;i<m;i++){
            if(found){scanf("%d%d%d",&t1,&t2,&t3); continue;}
            else{
                scanf("%d%d%d",&t1,&t2,&t3);
            while(t1<=1000000){
                for(j=t1+1;j<=t2;j++){
                    if(sche.test(j)) found = true;
                    else sche.set(j);
                    if(found) break;
                }
                t1 += t3;
                t2 += t3;
                t2 = min(t2,1000000);
                if(found) break; 
            }
            }
        }
        if(found) printf("CONFLICT\n");
        else printf("NO CONFLICT\n");
         sche.reset(); found = false;
}
}