#include<stdio.h>
#include<string.h>
int main()
{
 int len,i,j,freq=0;
 char a[50],c;
 printf("enter a sentence:");
 fgets(a,sizeof(a),stdin);
 len=strlen(a);
 for (i=0;i<=len;i++)
 {
  for (j=i;j<=len,j++)
  {
   if a[j]==a[i];
   {
    freq++;
   }
  }
  printf("frequency of %d is %d",a[i],freq)
 }
 
 return(0);
}