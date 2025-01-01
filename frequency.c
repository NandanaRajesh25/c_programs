#include<stdio.h>
#include<string.h>
int main()
{
 int len,i,freq=0;
 char a[50],c;
 printf("enter a sentence:");
 fgets(a,sizeof(a),stdin);
 len=strlen(a);
 printf("enter character whose frequency has to be found:");
 scanf("%s",c);
 for (i=0;i<=len;i++)
 {
  if (a[i]==c)
  {
   freq++;
  }
 }
 printf("frequency is %d",freq);
 return(0);
}