#include<stdio.h>
int strlen(char a[])
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}
int main()
{
	char s[20];
	gets(s);
	printf("%d",strlen(s));
}

