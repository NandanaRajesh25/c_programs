#include<stdio.h>
#include<string.h>
int main()
{
 int len,i,nw=1;
 char a[50],c;
 printf("enter a sentence:");
 fgets(a,sizeof(a),stdin);
 len=strlen(a);
 for (i=0;i<=len;i++)
 {
  if (a[i]==' ')
  {
   nw++;
  }
 }
 printf("no of words are %d",nw);
 return(0);
}