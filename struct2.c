#include<stdio.h>
struct employee
{
	char name[50];
	char empid[50];
	int salary;
};
int main()
{
	int n,i;
	struct employee emp[100];
	printf("enter no of records");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("enter details of emp %d",i+1);
		scanf("%s%s%d",emp[i].name,emp[i].empid,&emp[i].salary);
	}
	for (i=0;i<n;i++)
	{
		printf("details of emp %d\t",i+1);
		printf("Name: %s, Empid: %s,Salary: %d\n",emp[i].name,emp[i].empid,emp[i].salary);
	}
	return(0);  
}
