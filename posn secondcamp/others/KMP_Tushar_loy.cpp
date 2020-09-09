#include<bits/stdc++.h>
using namespace std;
char s1[10005],s2[10005];
int n,m,ans;
int lps[10005];
void kmpPreprocess(){
   int idx = 0;
   for(int i=1;i<m;){
        if(s2[i]==s2[idx]){
            lps[i] = idx+1;
            i++,idx++;
        }
        else {
            if(idx!=0) idx = lps[idx-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
   }
//    for(int i=0;i<m;i++){
//        printf("%d ",lps[i]);
//    }
}
void kmp(){
    int i=0,j=0;
     int lps[n];
    while(i<n&&j<m){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            if(j!=0) j = lps[i-1];
            else i++;
        }
        if(j==m){ans++;j = lps[j];}
    }
}
int main(){
   printf("TEXT : ");  
   scanf("%s",s1);
   n = strlen(s1);
   printf("PATTERN: ");
   scanf("%s",s2);
   m = strlen(s2);
  kmpPreprocess();
  kmp();
  cout << ans;
}