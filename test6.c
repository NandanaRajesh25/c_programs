#include <stdio.h>
#include <string.h>
struct lifo{
    char B[100];
    int top;
};
typedef struct lifo stack;

void Create(stack *s)
{ s->top=-1;
}

void push(char ch,stack *s)
{ 
      s->top++;
      s->B[s->top]=ch;
}

char pop(stack *s)
{   return s->B[s->top--];
     
    
} 

int isp(char ch)
{
    if(ch=='+'||ch=='-')
        return 2;
    else if(ch=='*'||ch=='/')
        return 4;
    else if(ch=='^')
        return 5;
    else if(ch=='(')
        return 0;
   
}

int icp(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 3;
    else if(ch=='^')
        return 6;
    else if(ch=='(')
        return 9;
    else if(ch==')')
        return 0;
    return 0;
}

int IsEmpty(stack *s)
{ return s->top;
}

int main()
{ 
  char A[100],C[100];
  stack s;
  Create(&s);
  printf("Enter expression:");
  fgets(A,sizeof(A),stdin);
  int len=strlen(A);
  int j=0;
  for(int i=0;i<len;i++)
   {
        char x=A[i];
        if((x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>=0&&x<=9))

              C[j++]=x;

        else if(x==')')

            { while(s.B[s.top]!='(')

                  C[j++]=pop(&s);
            
    
              s.top--;  
            }
        else 
            {

              while(IsEmpty(&s)!=-1 && isp(s.B[s.top]>=icp(x)))
                  C[j++]=pop(&s);  
              push(x,&s);
            }
   }        
  
  while(IsEmpty(&s)!=-1)

      C[j++]=pop(&s);
               

  C[j]='\0';  
  printf("postfix conversion is: %s",C);
	return(0);   
}