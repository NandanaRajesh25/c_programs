#include<stdio.h>
#include<string.h>
int main()
{
 int len,i,j;
 char a[50],b[25],c[25],large[25],small[25];
 printf("enter a sentence:");
 fgets(a,sizeof(a),stdin);
 len=strlen(a);
 for (i=0;i<=len;i++)
 {
  while (a[i]!=' ')
  {
   b[i]=a[i];
  }
  while (a[i]==' ')
  {
   for(j=0;a[j]!=' ';j++)
   {
    c[j]=a[i+1];
   }
  }
  if (strlen(b)>strlen(c))
  {
   strcpy(large,b);
   strcpy(small,c);
  }
  else
  {
   strcpy(large,c);
   strcpy(small,b);
  }
 }
 printf("largest and smallest words are %s, %s",large,small);
 return(0);
}