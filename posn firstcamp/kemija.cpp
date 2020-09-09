#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[]="apa";
    char s1[] = "epe";
    char s2[] = "ipi";
    char s3[] = "opo";
    char s4[] = "upu";
    int i,n=0;
    char w[105];
    gets(w);
    while(w[n]!='\0')
    {
        n++;
    }
    for(i=0;i<n;i++)
    {
        if(w[i]==s[0] && w[i+1]==s[1] &&w[i+2]==s[2])
        {
          printf("a");
          i+=3;
        }
        else if(w[i]==s1[0] && w[i+1]==s1[1] &&w[i+2]==s1[2])
        {
            printf("e");
          i+=3;
        }
        else if(w[i]==s2[0] && w[i+1]==s2[1] &&w[i+2]==s2[2])
        {
           printf("i");
          i+=3;
        }
        else if(w[i]==s3[0] && w[i+1]==s3[1] &&w[i+2]==s3[2])
        {
           printf("o");
          i+=3;
        }
        else if(w[i]==s4[0] && w[i+1]==s4[1] &&w[i+2]==s4[2])
        {
          printf("u");
          i+=3;
        }
       else printf("%c",w[i]);
    }


}



