#include<bits/stdc++.h>
using namespace std;
string fs,ss,ts;
int main(){
        int l,n;
        cin >> l >> n;
        int i,j,k=0;
        bool r = false;
        for(i=0;i<n;i++){
            cin >> fs;
            if(i>0&&r==false) {
            if(fs.length()!=l)
                {
                    ts = ss;
                    r  = true;
                }
            for(j=0;j<l;j++){
                if(fs[j]!=ss[j])
                    k++;
             if(k>2){
                ts = ss;
                r = true;
            }
            }
            }
            k = 0;
            ss = fs;
        }
        for(i=0;i<ts.length();i++)
            printf("%c",ts[i]);
        if(!ts.length()) for(i=0;i<fs.length();i++) printf("%c",fs[i]);

}
