#include<bits/stdc++.h>
using namespace std;
int N,Q,i,tmp;
int fwt[1000005][3],t1,x,y,R,G,B,color[1000005];
char c;
void update(int idx,int val,int di){
    while(idx <= N){
        fwt[idx][di] += val;
        idx += idx&(-idx);
    }
}
int query(int idx,int di){
    int sum = 0;
    while(idx>=1){
        sum += fwt[idx][di];
        idx -= idx&(-idx);
    }
    return sum;
}
int main(){
    scanf("%d%d",&N,&Q);
    for(i = 1 ; i <= N ; i++){
        color[i] = (i+2)%3;
        update(i,1,(i+2)%3);
    }
    //0 R 1 G 2 B
    while(Q--){
        scanf("%d",&tmp);
        if(tmp==1){
            scanf("%d %c",&t1,&c);
            if(c=='R' && color[t1]!=0){
                update(t1,1,0);
                update(t1,-1,color[t1]);
                color[t1]=0;
            }
            else if(c=='G'&&color[t1]!=1){   
                update(t1,1,1);
                update(t1,-1,color[t1]);
                color[t1]=1;

            }
            else if(c=='B'&&color[t1]!=2){
                update(t1,1,2);
                update(t1,-1,color[t1]);
                color[t1]=2;
            }
        }
        else {
            scanf("%d%d",&x,&y);
            R = query(y,0) - query(x-1,0);
            G = query(y,1) - query(x-1,1);
            B = query(y,2) - query(x-1,2);
            //printf("R = %d G = %d B = %d\n",R,G,B);
            if(R > G && R > B) printf("R\n");
            else if(G > R && G > B) printf("G\n");
            else if(B > R && B > G) printf("B\n");
            else printf("None\n");
        }
    }


}