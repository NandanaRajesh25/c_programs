#include<stdio.h>
#include<string.h>
union address
{
	char name[40];
	char hname[40];
	char city[40];
	char state[40];
	int pin;
};
int main()
{
	union address a;
	strcpy(a.name,"nandana");
	printf("%s\n",a.name);
	strcpy(a.hname,"mra");
	printf("%s\n",a.hname);
	strcpy(a.city,"tvm");
	printf("%s\n",a.city);
	strcpy(a.state,"kerala");
	printf("%s\n",a.state);
	a.pin=123455;
	printf("%d\n",a.pin);
	return(0);
}
