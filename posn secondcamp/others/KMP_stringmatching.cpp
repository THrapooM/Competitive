#include <bits/stdc++.h>    
using namespace std;
char P[100010], T[100010];
int b[100010];
int n, m, ans = 0;
void kmpPreprocess(){
int i = 0, j = -1;
b[0] = -1;
while(i < m){
while(j>=0 && P[i] != P[j])j = b[j];
i++, j++, b[i] = j;
}
for(int i=1;i<=m;i++){
    printf("%d ",b[i]);
}
printf("\n");
}
void kmp(){
int i = 0, j = 0;
while(i < n){
while(j>=0 && T[i] != P[j])j=b[j];
i++, j++;
if(j==m){printf("%d",i);ans++,j=b[j];}
printf("i = %dj = %d\n",i,j);
}
}
int main(){
m = strlen(gets(P)), n = strlen(gets(T));
kmpPreprocess(), kmp();
cout<<ans;
return 0;
}