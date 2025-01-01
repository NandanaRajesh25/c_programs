#include<stdio.h>
#include<math.h>
struct point1
{
	int x1,y1;
};
struct point2
{
	int x2,y2;
};
int main()
{
	float dist;
	struct point1 p1;
	struct point2 p2;
	printf("enter point 1 ");
	scanf("%d%d",&p1.x1,&p1.y1);
	printf("enter point 2 ");
	scanf("%d%d",&p2.x2,&p2.y2);
	dist=sqrt(pow((p2.x2-p1.x1),2)+pow((p2.y2-p1.y1),2));
	printf("%f",dist);
	return(0);
}
	
