#include<stdio.h>
#include<string.h>
int main()
{
 int len,i,b=0,found;
 char a[50],c;
 printf("enter a sentence:");
 fgets(a,sizeof(a),stdin);
 len=strlen(a);
 printf("enter character to remove:");
 scanf("%s",c);
 while (a[i]!='\0')
 {
  found=0;
  for (i=0;i<=len;i++)
  {
   if (a[i]==c)
   {
    b=i;
    found=1;
    break;
   } 
  }
  if (found==1)
  {
   for(i=b;i<=len;i++)
   {
    a[i]=a[i+1];
   }
  }
 }
 printf("new sentence is %s",a);
 return(0);
}