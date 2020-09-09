//https://programming.in.th/task/rev2_problem.php?pid=1105
#include<bits/stdc++.h>
using namespace std;
int n,k,i,t1;
vector<int>v;
int main(){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&t1);
        v.push_back(t1);
    }
    sort(v.rbegin(),v.rend());
    printf("%d ",v[k-1]);
}
