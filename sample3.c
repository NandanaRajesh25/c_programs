#include <stdio.h>
void sum(int R1,int C1,int R2,int C2, int A[50][50], int B[50][50]);
void prdt(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50]);
void trans(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50]);
void display(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50]);
int main()
{
 int i,j,code;
 int R1,R2,C1,C2,A[50][50],B[50][50];
 printf("Enter the number of rows and columns of the first matrix:");
 scanf("%d%d",&R1,&C1);
 printf("Enter the number of rows and columns of the second matrix:");
 scanf("%d%d",&R2,&C2);
 printf("Enter the elements in first matrix:");
 for(i=0;i<R1;i++)
 { for(j=0;j<C1;j++)
   scanf("%d",&A[i][j]); }
 printf("Enter the elements in second matrix:");
 for(i=0;i<R2;i++)
 { for(j=0;j<C2;j++)
   scanf("%d",&B[i][j]); }
 do {
     printf("MENU\n 1-sum, 2- product, 3-transpose, 4-display, 5-exit");
     if(code==1)
       sum(R1,C1,R2,C2,A,B);
     if(code==2)
       prdt(R1,C1,R2,C2,A,B);
     if(code==3)
       trans(R1,C1,R2,C2,A,B);
     if(code==4)
       display(R1,C1,R2,C2,A,B); }
     while(code!=5);
}

void sum(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50])
{ 
    if(R1==R2&&C1==C2)
    {   
        int C[50][50];
        for(int i=0;i<R1;i++)
        { for(int j=0;j<C1;j++)
        {  C[i][j]=A[i][j]+B[i][j];
          printf("%d\t",C[i][j]); 
        }
        printf("\n");
     }
    } else printf("dimension mismatch");
 }
 
void prdt(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50])
{ 
  int C[50][50];
  if(C1==R2)
  { for(int i=0;i<R1;i++)
      { for(int j=0;j<C2;j++)
       { C[i][j]=0;
         for(int k=0;k<C1;k++)
         C[i][j]+=A[i][k]*B[k][j]; }
  }
  for(int i=0;i<R1;i++)
        { for(int j=0;j<C2;j++)
          printf("%d\t",C[i][j]); 
        }
        printf("\n");
    }
    else printf("dimension mismatch");
}
void trans(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50])
{       printf("Transpose of first Matrix is:");
        int C[50][50],D[50][50];
        for(int i=0;i<C1;i++)
        { for(int j=0;j<R1;j++)
         { C[i][j]=A[j][i];
          printf("%d\t",C[i][j]); }
        printf("\n"); }
        printf("Transpose of second Matrix is:");
        for(int i=0;i<C2;i++)
        { for(int j=0;j<R2;j++)
         { D[i][j]=B[j][i];
          printf("%d\t",C[i][j]); }
          printf("\n"); }
    }
void display(int R1,int C1,int R2,int C2, int A[50][50],int B[50][50])
{ for(int i=0;i<R1;i++)
   {     for(int j=0;j<C1;j++)
          printf("%d\t",A[i][j]); 
        printf("\n");
   }
for(int i=0;i<R2;i++)
    {    for(int j=0;j<C2;j++)
          printf("%d\t",B[i][j]); 
        printf("\n");
    }
}