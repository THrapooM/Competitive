#include<bits/stdc++.h>
int n1,n2,n3,n4;
int main()
{
    char s;
    char k[100];
    int i=0;
    while(s!='\n')
    {
        scanf("%c",&s);
        k[i]= s;
        i++;
    }
    for(int j=0;j<i-1;j++)
    {
        if(k[j]>='A'&&k[j]<='Z') n1++;
        else if(k[j]>='a'&&k[j]<='z') n2++;
        else if(k[j]>='0'&&k[j]<='9') n3++;
        else n4++;
    }
    printf("%d %d %d %d",n1,n2,n3,n4);
}
