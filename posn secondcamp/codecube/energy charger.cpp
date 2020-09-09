#include<bits/stdc++.h>
//#define print(x,y) printf("%d %d\n",x,y)
using namespace std;
int mx,mi,a[1000005],l,r,n,lm,mid;
int eng(int x){
     int t = 0;
     int cnt =0;
     for(int i=0;i<n;i++){
        if (x < a[i]) return 0;
        if(t<a[i]){
        cnt++;
        t=x;
        }
        t-=a[i];
     }
     return cnt;
}
int main(){
    int i;
    scanf("%d%d",&n,&lm);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            mi = max(mi,a[i]);
        }
        if (lm == 1) {
            printf("-1");
            return 0;
        }
        l = mi,r = 1e9;
        while(1){
            mid = (l+r)>>1;
        //printf("%d %d %d\n",l,r,mid);
        if(eng(mid)==lm &&eng(mid+1)!=lm)break;
           else if(eng(mid)>=lm) l = mid+1;
           //mean if value eng mid low than limit so you need to push more value
           else if(eng(mid)<lm) r = mid-1;
        }
        int anshigh = mid;
        l = mi,r = 1e9;
//        for (i = 15; i > 0; i--){
//            print(i,eng(i));
//        }
        while(1){
            mid = (l+r)>>1;
            if(eng(mid)==lm &&eng(mid-1)!=lm) break;
            else if(eng(mid)<=lm){
                r = mid-1;
                //print(1);
            }
            else if(eng(mid)>lm){
                l = mid+1;
                //print(2);
            }
           //cout <<mid<<endl;
        }
        int anslow = mid;
        printf("%d",anshigh-anslow+1);

}

