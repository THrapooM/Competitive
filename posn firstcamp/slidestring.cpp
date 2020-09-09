#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int x,y;
	gets(s);
	y = strlen(s);
	for(x=0;x<y;x++)
	{
		if(s[x]=='l' || s[x]=='o' || s[x]=='v'||s[x]=='e')
		printf("%c",s[x]);
	}
	printf("\n");
	for(x=0;x<y;x++)
	{
		if(s[x]!='l' && s[x]!='o' && s[x]!='v'&&s[x]!='e')
		printf("%c",s[x]);
	}
}
