#include <stdio.h>
#include <stdlib.h>
struct polyterm
{
    int coeff;
    int exp;
    struct polyterm *link;
};

struct polyterm * Insert(struct polyterm *current,struct polyterm **start, int coeff, int exp)
{
    struct polyterm *p=(struct polyterm *)malloc(sizeof(struct polyterm));
    if(p==NULL)
        printf("Memory insufficent");
    else
    {
            if(current==NULL) 
            {
               p->coeff=coeff;
               p->exp=exp;
               p->link=NULL;
               *start=p;
               current=p;
            }
            else
            {
               p->coeff=coeff;
               p->exp=exp;    
               p->link=NULL;
               current->link=p;
               current=p;
            }
            return current;
    }
}


void Display(struct polyterm *start)
{
    printf(" \n The terms in the polynomial are: \n");
    while(start->link!=NULL)
    {    
        {
          printf("%dx^%d+",start->coeff,start->exp);
          start=start->link;
        }
    }
          if(start->exp==0)
                      printf("%d",start->coeff,start->exp);
          else
                      printf("%dx^%d",start->coeff,start->exp);

}


struct polyterm * Add(struct polyterm *start3, struct polyterm *start1, struct polyterm *start2)
{    
    struct polyterm *addstart;
    while(start1!=NULL && start2!=NULL)
    {   
                struct polyterm *p=(struct polyterm *)malloc(sizeof(struct polyterm));
                if(p==NULL)
                {
                   printf("Memory insufficent");
                   exit(-1);
                } 
                if(start1->exp==start2->exp)
                {   

                    p->coeff=start1->coeff+start2->coeff;
                    p->exp=start1->exp;
                    p->link=NULL;
                    if(start3!=NULL)
                            start3->link=p;
                    else
                            addstart=p;    
                    start3=p;
                    start1=start1->link;
                    start2=start2->link;
                    continue;
                }

                else if(start1->exp>start2->exp)
                     {
                        p->coeff=start1->coeff;
                        p->exp=start1->exp;
                        p->link=NULL;
                        if(start3!=NULL)
                            start3->link=p;
                        else
                            addstart=p;
                        start3=p;
                        start1=start1->link;
                        continue;
                     }

                     else if(start2->exp>start1->exp)
                          {
                             p->coeff=start2->coeff;
                             p->exp=start2->exp;
                             p->link=NULL;
                             if(start3!=NULL)
                                 start3->link=p;
                             else
                                 addstart=p;   
                             start3=p;
                             start2=start2->link;
                             continue;
                          }

    }
  

    while(start1!=NULL && start2==NULL)
    {
        struct polyterm *p=(struct polyterm *)malloc(sizeof(struct polyterm));
        if(p==NULL)
        {
            printf("Memory insufficent");
            exit(-1);
        }
        else
        {
                        p->coeff=start1->coeff;
                        p->exp=start1->exp;
                        p->link=NULL;
                        if(start3!=NULL)
                            start3->link=p;
                        else
                            addstart=p;
                        start3=p;
                        start1=start1->link;
        }   
    }

    while(start2!=NULL && start1==NULL)
    {
        struct polyterm *p=(struct polyterm *)malloc(sizeof(struct polyterm));
        if(p==NULL)
        {
            printf("Memory insufficent");
            exit(-1);
        }
        else
        {
                             p->coeff=start2->coeff;
                             p->exp=start2->exp;
                             p->link=NULL;
                             if(start3!=NULL)
                                 start3->link=p;
                             else
                                 addstart=p;   
                             start3=p;
                             start2=start2->link;
        }   
    } 
    return addstart;            
}


int main()
{
    int n1,n2,i,coeff,exp;
    /* 
       deg1-degree of 1st polynomial
       deg2-degree of 2nd polynomial
       i-loop variable
       coeff-co-efficent
       exp-exponential power
     */
    struct polyterm *start1=NULL;
    struct polyterm *start2=NULL;
    struct polyterm *start3=NULL;
    struct polyterm *current=NULL;
    struct polyterm *addstart=NULL;   
 
    printf("\n Enter the number of terms of the first polynomial: \n");
    scanf("%d",&n1);

    printf("\n Enter the items of the first polynomial: \n");
    for(i=1;i<=n1;i++)
    {
        printf("Enter the co-efficent:");
        scanf("%d",&coeff);
        printf("Enter the exponent:");
        scanf("%d",&exp);
        current=Insert(current,&start1,coeff,exp);
    }
  
    current=NULL;

    printf("\n Enter the number of items in the second polynomial: \n");
    scanf("%d",&n2);
    printf("\n Enter items in the second polynomial: \n");
    for(i=1;i<=n2;i++)
    {
        printf("Enter the co-efficent:");
        scanf("%d",&coeff);
        printf("Enter the exponent:");
        scanf("%d",&exp);
        current=Insert(current,&start2,coeff,exp);
    }
  
    
    //Adding the two polynomials
    addstart=Add(start3,start1,start2);
    printf(" \n The added polynomial is: \n");
    Display(addstart);
}