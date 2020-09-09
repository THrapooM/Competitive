#include <bits/stdc++.h>
using namespace std;

int m,n,a;
int tk[100005];
int tsk[1000005],ord[1000005],patt[1000005];

void pattern()
{
    int i=0,j=-1;
    ord[0]=-1;
    while(i<n)
    {
        while(j>=0&&patt[i]!=patt[j]) j=ord[j];
        ord[++i]=++j;
    }
}
int kmp()
{
    int i=0,j=0,cnt=0;
    while(i<m)
    {
        while(j>=0&&tsk[i]!=patt[j])j=ord[j];
        i++,j++;
        cnt=max(cnt,j);
        if(j==n)return cnt;
    }
    return cnt;
}

int main(){
    for(int i=1;i<=1e5;i++)
    {
        for(int j=1;j<sqrt(i);j++)
        {
            if(i%j==0)tk[i]+=2;
        }
        if(i==sqrt(i)*sqrt(i))tk[i]++;
    }
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a);
        tsk[i]=tk[a];
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        patt[i]=tk[a];
    }
    pattern();
//    for(int i=0;i<n;i++)printf("%d ",ord[i]);
    printf("%d",kmp());
}
