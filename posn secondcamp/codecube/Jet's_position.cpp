#include<bits/stdc++.h>
using namespace std;
int N,R[100005],L[100005],stl,str,enl,enr,num,i,valr,vall,maxl,maxr,strr,stll;
int suml,sumr,templ,tempr;
char c;
bool found;
int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf(" %c%d",&c,&num);
        if(c=='R'){
            R[i] = num;
            L[i] = -num;
            sumr += R[i];
            found = true;
        }
        else if(c=='L'){
            L[i] = num;
            R[i] = -num;
            suml += L[i];
        }
    }
    for(i=1;i<=N;i++){
        valr += R[i];
        if(valr < 0){
            valr = 0;
            str = i;
        }
        if(maxr < valr){
            maxr = valr;
            strr = str;
            enr = i;
        }
        vall += L[i];
        if(vall < 0){
            vall = 0;
            stl = i;
        }
        if(maxl < vall){
            maxl = vall;
            stll = stl;
            enl = i;
        }
  //printf("%d %d %d %d %d %d\n",maxr,strr,enr,maxl,stll,enl);
    }
   tempr = sumr + maxl;
   templ = suml + maxr;
//    printf("%d %d ",tempr,templ);
   if(tempr > templ) printf("R %d %d %d",tempr,stll+1,enl);
   else if(tempr < templ) printf("L %d %d %d",templ,strr+1,enr);
   else {
       if(found) printf("L %d %d %d",templ,strr+1,enr);
       else printf("R %d %d %d",tempr,stll+1,enl);
   }
   
}