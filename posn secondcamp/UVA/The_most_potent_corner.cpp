    #include<bits/stdc++.h>
    using namespace std;
    int n,a[1<<15+5],i,j,t1,wei[1<<15+5],maxx=-1e9;
    int main(){
        while(cin >> n){
                for(i=0;i<1<<n;i++){
                    scanf("%d",&t1);
                    a[i] = t1;
                }
                for(i=0;i<1<<n;i++){
                    for(j=0;j<n;j++)
                    wei[i] += a[i^(1<<j)];
                    //store[i] = wei[i];
                // printf("%d\n",store[i]);
                }
                for(i=0;i<1<<n;i++){
                    for(j=0;j<n;j++){
                        maxx = max(maxx,wei[i]+wei[i^(1<<j)]);
                    }
                }  
                cout << maxx << endl;
                maxx = -1e9;
                memset(wei,0,sizeof(wei));
                

    }
    }