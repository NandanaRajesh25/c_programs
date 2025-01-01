#include <stdio.h>
#include<string.h>
int main() {
    char A[50];
    int i,sp=0,alpha=0,dig=0,l;
    printf("Enter the string\t");
    fgets(A,sizeof(A),stdin);
    l=strlen(A);
    for(i=0;i<l;i++){
        if (A[i]==' '){
            sp=sp+1;
        }
        else if((A[i]>=97 && A[i]<=122)||(A[i]>=65 && A[i]<=90)){
            alpha=alpha+1;
        }
        else if(A[i]=='\n')
        {
            printf("test");
            dig=dig+1;
            
        }
    }
    printf("Length of the string is %d\n",l);
    printf("The no of Alphabets is %d\n",alpha);
    printf("The no of spaces is %d\n",sp);
    printf("The no of digits is %d\n",dig);
    return 0;
}
