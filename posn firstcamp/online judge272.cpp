/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    char line[1024];
    bool open = 1;
    int len,i;
    while(gets(line))
    {
        len = strlen(line);
        {
            for(i=0;i<len;i++)
            {
                if(line[i]=='"')
                {
                    if(open==1)
                    {
                        printf("``");
                    }
                    else if(!open)
                    {
                        printf("''");
                    }
                    open = !open;
                }
                else printf("%c",line[i]);
            }
            printf("\n");
        }
    }
    return 0;
}*/
#include<bits/stdc++.h>
int main()
{
    char s;
    int k = 0;
    while(scanf("%c",&s)==1)
    {
        if(s=='"')
        {
            if(k%2==0) printf("``");
            else if(k%2==1) printf("''");
            k++;
        }
        else printf("%c",s);
    }
    return 0 ;
}
