#include<stdio.h>
#include<math.h>
int fact(int b);
int main()
{
 int n,i,m=3,x,p=0;
 printf("enter number of terms:");
 scanf("%d",&n);
 printf("enter value of x:");
 scanf("%d",&x);
 printf("req sine series is: ");
 printf("%d",x);
 for (i=2;i<=n;i++)
 {
  p=pow(x,m);
  if (i%2==0)
  {
   printf(" - %d/%d",p,fact(m));
   m=m+2;
  }
  else
  {
   printf(" + %d/%d",p,fact(m));
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