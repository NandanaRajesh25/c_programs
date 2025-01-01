#include<stdio.h>
#include<math.h>
struct Point{
 int x;
 int y;
}P1,P2;
int main()
{
 float dist;
 printf("enter x1,y1: ");
 scanf("%d%d",&P1.x,&P1.y);
 printf("enter x2,y2: ");
 scanf("%d%d",&P2.x,&P2.y);
 dist=sqrt(pow(P1.x-P2.x,2)+pow(P1.y-P2.y,2));
 printf("dist is %f",dist);
 return 0;
}  