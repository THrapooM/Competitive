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
	for(c=0;c<a;c++)
	{
		for(d=0;d<b;d++)
		{
			if(s1[c]==s2[d] || s1[c]==s2[d]+32 || s1[c]==s2[d]-32)
			{
				s1[c]=27;
				s2[d]=27;
            }
        }
	}
	if(strcmp(s1,s2)==0)
	printf("Yes");
	else printf("No");

}
