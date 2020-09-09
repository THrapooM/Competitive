#include<bits/stdc++.h>

using namespace std;

int c,n;

    int i,a[100];
int f(int x)
{
    if(x==c+n)
    {
        int cc=0,cn=0;
        for(int i=0;i<c+n;i++)
        {
            if(a[i]==0) cc++;
        }
        if(cc==c)
        {
            for(int i=0;i<c+n;i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
        }
    else
    {
        for(int i=0;i<=1;i++)
        {
            a[x] = i;
            f(x+1);
        }
    }
}

int main()
{
    cin >> c >> n;
    for(int i=0;i<c+n;i++) a[i] = 0;
    f(0);
}
