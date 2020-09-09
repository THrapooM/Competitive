#include<bits/stdc++.h>
using namespace std;
int heibox[500005],heipow[500005],t1,t2,t3,i,N,maxx = 1e9,evrb,total[500005],ans1 = 1e9,ans2 = 1e9;
bool use[500005];
vector<int>v;
int main(){
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&heibox[i]);
        maxx = min(maxx,heibox[i]);
    }
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&heipow[i]);
        if(heipow[i] < maxx) evrb +=  heipow[i] + heibox[i] - maxx;
        else {evrb += heipow[i] - maxx;
        }
        if(heipow[i] <= maxx && !use[heipow[i]]) v.push_back(heipow[i]),use[heipow[i]] = true;
        total[heipow[i]] += heibox[i];
    }
    total[maxx] = 0;
    sort(v.rbegin(),v.rend());
    for(i = 1 ; i < v.size() ; i++){
        total[v[i]] += total[v[i-1]];
    }
    for(i = 0 ; i < v.size() ; i++){
        t1 = v[i];
        evrb += (maxx - v[i]) * N;
        evrb -= (total[t1] - total[maxx]);
        if(ans1 > evrb){
            ans1 = evrb;
            ans2 = t1;
        }
        else if(ans1 == evrb) ans2 = t1;
        maxx = t1;
    }
    printf("%d %d\n",ans2,ans1);
}
