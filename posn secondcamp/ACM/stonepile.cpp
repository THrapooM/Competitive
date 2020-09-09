    #include<bits/stdc++.h>
using namespace std;
int a[25];
int x,val = 1e9,v[25];
int n,i;
void stonepile(int x)
{
    if(x<n)
    {
        a[x] = 1;
        stonepile(x+1);
        a[x]= 0;
        stonepile(x+1);
    }
    else
    {
       int ans = 0;
       for(i=0; i<n; i++)
        {
            if(a[i])
                ans+=v[i];
            else
                ans-=v[i];
        }
        val = min(val,abs(ans));
    }
}
int main()
{
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&v[i]);
    stonepile(0);
    cout << val;
    return 0;
}
