 #include<stdio.h>
#include<string.h>
int main()
{
	char s1[20],s2[20];
		int a,b,c,d,f=0;
		printf("your String1: ");
		gets(s1);
		printf("your string2: ");
		gets(s2);
		a = strlen(s1);
		b = strlen(s2);
	if(a!=b)
	printf("No");
	int t=0;
	for(c=0;c<a;c++)
	{   t=0;
		for(d=0;d<b;d++)
		{
			if(s1[c]==s2[d] || s1[c]==s2[d]+32 || s1[c]==s2[d]-32)
			{
				t=1;
				s2[d]='0';
				break;
            }
        }
        if(t==1) continue;
        printf("no");
        return 0;
	}
	printf("Yes");
}
