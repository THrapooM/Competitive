#include<bits/stdc++.h>

using namespace std;

long long mx[500005],pos[500005];
long long mxx = 1e18;
long long everyboxgototmx = 0;
vector<long long> v;
long long ump[500005];
unordered_map<long long,bool> check;
int main()
{
int n;
int i;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%lld",&mx[i]);
mxx = min(mxx,mx[i]);
}
cout << mxx;
for(i=1;i<=n;i++)
{
scanf("%lld",&pos[i]);
if(pos[i]<mxx) everyboxgototmx += pos[i]+mx[i]-mxx;
else everyboxgototmx += pos[i]-mxx;
printf("i = %d evrb = %d\n",i,everyboxgototmx);
if(pos[i]<=mxx && !check[pos[i]])
    {
        v.push_back(pos[i]);
        check[pos[i]] = true;
    }
ump[pos[i]] += mx[i];
}
ump[mxx] = 0;
long long ans1 = 1e18,ans2 = 1e18;
long long t = everyboxgototmx;
printf("t = %d",t); return 0;
sort(v.rbegin(),v.rend());
for(i=1;i<v.size();i++)
{
ump[v[i]] += ump[v[i-1]];
}
//printf("%lld ",v[0]);
long long before = mxx;
for(i=0;i<v.size();i++)
{
long long l = v[i];
printf("1  = l = %d\n\n",l);
//printf("t = %18lld ump[l] = %18lld ump2[l] = %18lld ans1 = %18lld\n",t,ump[l],ump2[l],ans1);
t += ((before-l)*n);
printf("2 = l = %d\n",l);
t -= (ump[l]-ump[before]);
printf("3 = t = %d l = %d\n",t,l);
if(ans1>t)
{
    ans1 = t;
    ans2 = l;
}
else if(ans1==t)
{
    ans2 = l;
}
//printf("%lld %lld %lld %lld\n",t,ump[l],ump[before],l);
before = l;
}
printf("%lld %lld",ans2,ans1);

}