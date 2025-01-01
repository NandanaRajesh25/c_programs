#include<stdio.h>
#include<math.h>
int fact(int b);
int main()
{
 int n,i,a=1;
 printf("enter number of terms:");
 scanf("%d",&n);
 printf("req exponential series is: ");
 printf("%d",a);
 for (i=1;i<n;i++)
 {
  printf(" + x^%d/%d",i,fact(i));
 }
 return(0);
}
  

int fact(int b)
{
 int fact=1,j;
 for (j=1;j<=b;j++)
 {
  fact=fact*j;
 }
 return (fact);
}