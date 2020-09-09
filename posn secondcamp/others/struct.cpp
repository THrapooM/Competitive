#include<bits/stdc++.h>
using namespace std;
 int t2;
struct k{
    int x,y;
    bool operator < (const k t) {
       if(y!=t.y) return y < t.y;
    }
};
vector <k> v;
int main(){
        int i ,num,num1;
        for(i=0;i<5;i++)
        {
            cin >> num >> num1;
            v.push_back({num,num1});
        }
        sort(v.begin(),v.end());
        for(i=0;i<5;i++){
            cout << v[i].x << " "<< v[i].y << endl;
        }
}
