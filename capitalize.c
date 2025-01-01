#include<stdio.h>
#include<string.h>
int main()
{
 int len,i;
 char a[50];
 len=strlen(a);
 printf("enter a sentence:");
 fgets(a,sizeof(a),stdin);
 for (i=0;i<=len;i++)
 {
  if ((a[i]>='a' && a[i]<='z') || (a[i]==' '))
  {
   if (i==0)
   { 
    a[i]=a[i]-32;
   }
   else if (a[i]==' ')
   {
    a[i+1]=a[i]-32;
   }
  }
 }
printf("%s",a);
return(0);
}