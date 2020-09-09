#include<bits/stdc++.h>
using namespace std;
vector<string>v;
int que,row,lenf,i,lens,j,k;
string s1,s2,s3;
unordered_map<string,bool>m;
bool check;
int main(){
    scanf("%d%d",&row,&lens);
    for(i=0;i<row;i++){
        cin >> s1;
        v.push_back(s1);
    }
    scanf("%d",&que);
    //lenf=16,les=5
    for(j=0;j<que;j++){
        scanf("%d",&lenf);
        cin >> s2;
     for(k=0;k<lenf-lens+1;k++){
          m[s2.substr(k,lens)] = true;     
            }
           // check = false;
        for(i=0;i<row;i++){
            if(m[v[i]]) {printf("%d ",i+1);
            check = true;
            }
        }
        if(!check) printf("OK");
        printf("\n");
        check = false;
        m.clear();
    }
}