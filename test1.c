#include <stdio.h>
#include <string.h>
#include <math.h>
struct lifo
{
    char B[100];
    int top;
};

typedef struct lifo stack;

struct fifa
{
    float A[100];
    int Atop;
};
typedef struct fifa eval;

void Create(stack *s)
{ s->top=-1;
}

void Create1(eval *s)
{ s->Atop=-1;
}


void push(char ch,stack *s)
{ 
      s->top++;
      s->B[s->top]=ch;
}

char pop(stack *s)
{   return s->B[s->top--];
     
} 

float pop1(eval *s)
{   return s->A[s->Atop--];
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

void push1(eval *res,float f)
{   
      res->Atop++;
      res->A[res->Atop]=f;
}  


float postfixeval(char C[100])
{   eval res;
    Create1(&res);
    int len=strlen(C);
    for(int i=0;i<len;i++)
    {      
           char x=C[i];
           float val;
           if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
           {     
                printf("Enter the value of %c:",x);
                scanf("%f",&val);
                push1(&res,val);
           }
           //assumption: alphabetic expression is given
           else  if (x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
                {   
                     float res1;
                     float n2=pop1(&res);
                     float n1=pop1(&res);              
                     switch(x)
                     {
                       case '*': res1=n1*n2;
                                 push1(&res,res1);
                                 break;

                       case '/': res1=n1/n2;
                                 if(n2==0)
                                 {  printf("Division not possible");
                                    break;
                                 }   
                                 push1(&res,res1);
                                 break;

                       case '+': res1=n1+n2;
                                 push1(&res,res1);
                                 break;

                       case '-': res1=n1-n2;
                                 push1(&res,res1);
                                 break;

                       case '^': res1=pow(n1,n2); 
                                 push1(&res,res1);
                                 break;  
                     }
                }
    }

    return pop1(&res);
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
        {
             while(s.B[s.top]!='(')

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
  printf("result of postfix evaluation=%f",postfixeval(C));
	return(0);   
}