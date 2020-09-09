#include<bits/stdc++.h>
using namespace std;
    int n,k,i;
int visited[2000][2];
int kbased(int i,int bzero){
        if(i==n) return 1;
        if(visited[i][bzero]) return visited[i][bzero];
        else{
           visited[i][bzero] = (k-1)*kbased(i+1,0);

            if(!bzero) visited[i][bzero]  += kbased(i+1,1);
            return visited[i][bzero] ;
        }
}
int main(){
    cin >> n >> k;
    cout << kbased(0,1);
    return 0;


}

