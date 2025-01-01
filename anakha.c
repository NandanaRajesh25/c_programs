#include <stdio.h>
#include <string.h>
#define maxsize 100
struct lifo{
    int st[maxsize];
    int top;
};
typedef struct lifo stack;
int isp(char);
int icp(char);
void push(stack *,char);
void pop(stack *,char);
void create(stack *);
int main(){
    char inf[50];
    int i;
    stack stck;
    printf("Enter infix expression:");
    scanf("%s",inf);
    create(&stck);
    for (i=0;i<=strlen(inf);i++){
        if ((inf[i]>=97 && inf[i]<=122) || (inf[i]>=65 && inf[i]<=90)){
            printf("%c",inf[i]);
        }
        else if(inf[i]=='\0'){
            pop(&stck,inf[i]);
        }
        else{
            push(&stck,inf[i]);
        }
    }
    return 0;
}

void create(stack *s){
    s->top=-1;
    return;
}
int isp(char oprtr){
    switch (oprtr){
                case '*':
                    return 4;
                case '/':
                    return 4;
                case '+':
                case '-':
                    return 2;
                case '^':
                    return 5;
                case '(':
                    return 0;
                
    }
}

int icp(char oprtr){
    switch (oprtr){
            case '*':
                return 3;
            case '/':
                return 4;
            case '+':
            case '-':
                return 1;
            case '^':
                return 6;
            case '(':
                return 9;
            case ')':
                return 0;
    }
}
void push(stack *s,char oprtr){
    
    if (s->top==-1){
          s->top++;
          s->st[s->top]=oprtr;
    }
    else if (icp(oprtr)<=isp(s->st[s->top])){
        pop(s,oprtr);
    }
    else{
        s->top++;
        s->st[s->top]=oprtr;
    }
    return;
}

void pop(stack *s,char oprtr){
    
    int i;
    if (oprtr==')'){
        for (i=s->top;s->st[i]!='(';i--){
            printf("%c",s->st[i]);
            s->top--;
        }
    }
    else if (oprtr=='\0'){
        while (s->top >= 0) {
            if (s->st[s->top]=='('){
                s->top--;
                continue;
        }
            printf("%c",s->st[s->top]);
            s->top--;
        }
    }
    else{
        printf("%c",s->st[s->top]);
        s->top--;
        push(s,oprtr);
	}
	return;
}