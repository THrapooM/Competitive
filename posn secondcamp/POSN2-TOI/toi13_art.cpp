    #include<bits/stdc++.h>
    using namespace std;    
    int N,target,i,t1,t2,t3,t4,MAXH,MAXL,j,ans,l,r,mid,lower,upper,tmp,mid1,mid2;
    bool f;
    int fwt[1000005];
    struct axis{
        int h,val;
    };
    void update(int idx,int val){
        while(idx <= MAXH){
            fwt[idx] += val;
            idx += idx&-idx;
        }
    }
    int fsum(int idx){
        int sum = 0;
        while(idx >=1){
            sum += fwt[idx];
            idx -= idx&-idx;
        }
        return sum;
    }
    vector<axis>vec[4000005];
    int main(){
        scanf("%d%d",&N,&target);
        for(i = 1 ; i <= N ; i++){
            scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
            vec[t1].push_back({t2,t4});
            vec[t1+t3].push_back({t2,-t4});
            MAXH = max(MAXH,t2);
            MAXL = max(MAXL,t1+t3);
        }
        for(i = 1 ; i <= MAXL ; i++){
            for(j = 0 ; j < vec[i].size() ; j++){
                    update(MAXH-vec[i][j].h+1,vec[i][j].val);
                    f = true;
            }
            if(f)
            {
            int l1 = 1,r1 = MAXH,mid1;
            while(l1 <= r1){
                mid1 = (l1 + r1) >> 1;
                if(fsum(MAXH-mid1+1) > target) l1 = mid1+1;
                else r1 = mid1-1;
            }
            lower = l1;
        // printf("up l = %d r = %d mid = %d\n",l,r,mid);
            int l2 = 1,r2 = MAXH,mid2;
            while(l2 <= r2){
                mid2 = (l2 + r2) >> 1;
                if(fsum(MAXH-mid2+1) >= target) l2 = mid2+1;
                else r2 = mid2-1;
            }
        //   printf("low l = %d r = %d mid = %d\n",l,r,mid);
            upper = l2;
            tmp = upper-lower;
            if(!mid1) tmp = 0;
            }
            ans += tmp;
            f = false;
        }
        printf("%d",ans);

    }  