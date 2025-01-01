#include<stdio.h>
#include<string.h>
void reverse(char n[]);
int main()
{
	char a[50];
	printf("enter string");
	scanf("%s",a);
	reverse(a);
	return(0);
}

void reverse(char n[50])
{
	int len,i,j=0;
	char b[50];
	len=strlen(n);
	for (i=len-1;i>=0;i--)
	{
		b[j]=n[i];
		j++;
	}
	b[j]='\0';
	printf("reverse is %s",b);
	return;
}

