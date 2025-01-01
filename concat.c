#include<stdio.h>
int main()
{
 int i=0,j=0;
 char a[50],b[50],c[50];  
 printf("enter strings: ");
 scanf("%s%s",a,b);
 while (a[i]!='\0')
 {
  c[i]=a[i];
  i++;
 }
 a[i]='$';
 a[i+1]='\0';
 while (b[j]!='\0')
 {
  c[i]=b[j];
  i++;
  j++;
 }
 b[j]='$';
 b[j+1]='\0';
 c[i]='$';
 c[i+1]='\0';
 printf("input strings are %s and %s\n",a,b);
 printf("concatenated string is: %s",c);
 return(0);
}