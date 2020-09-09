#include<cstdio>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    int x[] = {-2,-2,-1,-1,1,1,2,2};
    int y[] = {1,-1,2,-2,2,-2,1,-1};
    char  s[3];
    int a=0,b=0,a1=0,b1=0;
    while(num--)
    {
        scanf("%s",s);
        a = s[0] -'a';
        b = s[1] -'1';
        int ans = 0;
        for(int i=0;i<8;i++)
        {
            a1 = a + x[i];
            b1 = b + y[i];
            if(a1>=0 && a1<=7 &&b1>=0 && b1<=7)
                ans++;
        }
        printf("%d",ans);
    }
    return 0 ;
}
