#include<stdio.h>
struct Employee{
 char Name[30];
 int Employee_Id[10];
 float Salary;
};
int main()
{
 struct Employee A[100];
 int i,n;
 printf("enter no of emp: ");
 scanf("%d",&n);
 for (i=1;i<n+1;i++){
  printf("enter name: \n");
  scanf("%s",A[i].Name);
  printf("enter emp id: \n");
  scanf("%d",A[i].Employee_Id);
  printf("enter salary: \n");
  scanf("%f",A[i].Salary);
 }
 for (i=1;i<n+1;i++){
  printf("name is: %s",A[i].Name);
  printf("emp id is: %d",A[i].Employee_Id);
  printf("salary is: %f",A[i].Salary);
 }
 return 0;
}