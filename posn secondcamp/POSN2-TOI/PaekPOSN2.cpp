#include<bits/stdc++.h>
using namespace std;
int i,j,k,N,x,cnt;
vector<int>v;
unordered_map<int,bool>m;
int a[5000005];
int main(){
    scanf("%d%d",&N,&k);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(i==1){
            if(a[i-1]>a[i]&&!m[a[i-1]])
        {
        m[a[i-1]]=true; v.push_back(a[i-1]);
        }
          }
        else if(a[i-1]>a[i-2]&&a[i-1]>a[i]&&! m[a[i-1]])
        { 
        m[a[i-1]]=true; v.push_back(a[i-1]);
        }
        else if(i==N-1){if(a[i]>a[i-1]&&!m[a[i]])
        {
         m[a[i]]=true; v.push_back(a[i]);
        }
        }
    }
   // cout << 1;
    if(v.size()==0) {printf("-1"); return 0;}
  //  cout << nv.size();
   if(v.size()>=k) sort(v.rbegin(),v.rend());
   else sort(v.begin(),v.end());
    for(i=0;i<v.size();i++){
        
        printf("%d\n",v[i]);
        cnt++;
        //cout << cnt;
        if(cnt==k) return 0;
    }
}