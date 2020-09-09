#include<bits/stdc++.h>
using namespace std;
int i,j,E;
char t1,t2;
char n,c;
string s,cc;
vector<char>from[200];
int a[200],minn=1e9,st=1e9;
int mem[205][205];
bool k = true,check;
void dfs(char x,string y){
      //  cout << y.length() << endl;
      if(check) return;
       if(y.length()==E+1&&check==false){
           // cout << 2;
            for(int j=0;j<y.length();j++){
                printf("%c ",y[j]);
            }
            check = true;
            return;
        }
        //cout << y.length()  << y << endl;
       // string t = y;
        for(int i=0;i<from[x].size();i++){
            if(!mem[x][from[x][i]]){
                mem[x][from[x][i]]  = mem[from[x][i]][x] = true;
                dfs(from[x][i],y+from[x][i]);
                mem[x][from[x][i]]  = mem[from[x][i]][x] = false;
            }
        }
                return;
}
int main(){
    scanf("%d",&E);
    for(i=0;i<E;i++){
        scanf(" %c %c",&t1,&t2);
        from[t1].push_back(t2);
        from[t2].push_back(t1);
        a[t1]++;
        a[t2]++;
         c = t1;
        cc = c;
    }
    for(i='A';i<='Z';i++){
       if(a[i]%2==1&&st>a[i]){
           st = a[i];
           n = i;
           s = n;
           k = false;
        }
    }
  //  cout << n << " " << s;
  if(k==true) dfs(c,cc); 
   else  dfs(n,s);
}