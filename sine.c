#include<stdio.h>
int fact(int b);
int main()
{
 int n,i,m=3;
 printf("enter number of terms:");
 scanf("%d",&n);
 printf("req sine series is: ");
 printf("x");
 for (i=2;i<=n;i++)
 {
  if (i%2==0)
  {
   printf(" - x^%d/%d",m,fact(m));
   m=m+2;
  }
  else
  {
   printf(" + x^%d/%d",m,fact(m));
   m=m+2;
  }
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