#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int s3[1000005];
int main()
{
    cin >> s1 >> s2;
    int x  = (int) s1.length();
    int y  = (int) s2.length();
    if(x!=y)
    {
        printf("R.I.P.");
        return 0;
    }
    int i;
    for(i=0; i<x; i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    for(i=0; i<x; i++)
    {
        if(s1[i]>=s2[i])
        {
            s3[i] = s1[i]-s2[i];
            if(s3[i]>9)
            {
                printf("R.I.P.");
                return 0;
            }
        }
        else if(s1[i]<s2[i])
        {
            if(s1[i]-s2[i]>=-25&&s1[i]-s2[i]<=-17)
                s3[i] = s1[i]-s2[i]+26;
            else
            {
                printf("R.I.P.");
                return 0;
            }
        }
    }
    for(i=0; i<x; i++)
    {
        printf("%d",s3[i]);
    }
}
