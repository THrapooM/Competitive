    #include<bits/stdc++.h>
    using namespace std;
    struct axis{
        int x,y;
        bool operator < (axis k) const{
        if(x!=k.x) return k.x<x;
        return k.y > y;     
        }
    }a[1000005];
    int N,val = 0,i;        
    int main(){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a,a+N);
        for(i=0;i<N;i++){
            if(val<=a[i].y){
                printf("%d %d\n",a[i].x,a[i].y);
                val = a[i].y;
            }
        }
    }