#include<bits/stdc++.h>
using namespace std;
int a[105],mem[105];
int n;
int cnt=0;
int num(int x,int val)
{
    int c = 0;
    if(x==n) return 0;
    if(a[x] >val) c = num(x+1,a[x])+1;
    return max(c,num(x+1,val));
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    cout << num(0,-1e9);

}
//#include<bits/stdc++.h>
//using namespace std;
//int N,mem[105][105],n[105],i;
//int lis(int x,int val){
//    if(x==N) return 0;
//    if(mem[x][val]) return mem[x][val];
//    if(n[x]>val) mem[x][val] = lis(x+1,n[x])+1;
//    return mem[x][val] = max(mem[x][val],lis(x+1,val));
//
//}
//int main(){
//    scanf("%d",&N);
//    for(i=0;i<N;i++){
//        scanf("%d",&n[i]);
//    }
//    cout << lis(0,0);
//}

