//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1796
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,big[1005][1005],small[4][1005][1005],store[4],k,cnt;
bool found;
string s;
// void check(){
//     for(int i=0;i<4;i++){
//         for(int j=0;j<m;j++){
//             for(int k=0;k<m;k++){
//                 printf("%c ",small[i][j][k]);
//             }
//             printf("\n");
//         }
//         printf("\n\n");
//     }
// }
void find(int x){
    //int cnt = 0;
        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                for(int k=0;k<m;k++){
                    for(int kk=0;kk<m;kk++){
                        if(big[k+i][kk+j]!=small[x][k][kk]) found = true;
                        else found = false;
                        if(found) break;
                    }
                    if(found) break;
                }
                if(!found) cnt++;
                found = false;
                }
            }
           // printf("x = %d %d\n",x,cnt);
        return;
        }
int main(){
    while(cin >> n >> m){
            if(!n&&!m) return 0;
            for(i=0;i<n;i++){
                cin >> s;
                for(j=0;j<n;j++){
                    big[i][j] = s[j];
                }
            }
            for(i=0;i<m;i++){
                cin >> s;
                for(j=0;j<m;j++){
                    small[0][i][j] = s[j];
                    small[1][j][m-i-1] = s[j];
                    small[2][m-i-1][m-j-1] = s[j];
                    small[3][m-j-1][i] = s[j];
                }
            }
           // check();
           for(k=0;k<4;k++){
               find(k);
               store[k] = cnt;
               cnt = 0;
           }
       printf("%d %d %d %d\n",store[0],store[1],store[2],store[3]);
        //printf("\n");  
    }
}