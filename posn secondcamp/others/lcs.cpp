//longest common subsequence
#include<bits/stdc++.h>
using namespace std;
    string A,B;
int lcs(int x,int y){
    if(x==0||y==0) return 0;
    if(A[x-1]==B[y-1]) return lcs(x-1,y-1)+1;
    return max(lcs(x-1,y),lcs(x,y-1));

}
int main(){
    cin >> A >> B;
    printf("the length of LCS is %d",lcs(A.length(),B.length()));
}
