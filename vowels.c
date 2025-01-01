#include<stdio.h>
#include<string.h>
int main()
{
 char a[100];
 int v=0,c=0,s=0,d=0,i,len;
 printf("enter string");
 fgets(a,s,stdin);
 len=strlen(a);
 a[len]='$';
 a[len+1]='\0';
 printf("%d",len);
 for (i=0;a[i]!='\0';i++)
 {
  if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
  {
   v++;
  }
  else if ((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
  {
   c++;
  }
  else if (a[i]==' ')
  {
   s++;
  }
  else if (a[i]>='0' && a[i]<='9')
  {
   d++;
  }
 }
 printf("no of vowels are: %d\n",v);
 printf("no of consonants are: %d\n",c);
 printf("no of spaces are: %d\n",s);
 printf("no of digits are: %d\n",d);
 return(0);
}
 
 
 