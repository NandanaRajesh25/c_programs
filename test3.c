#include <stdio.h>
union address{
    char Name[50];
    char HN[50];
    char city[50];
    char state[50];
    int pin;
}H1;
int main()
{
    printf("Enter the Name");
    scanf("%s",H1.Name);
    printf("Enter the House Name");
    scanf("%s",H1.HN);
    printf("Enter the City");
    scanf("%s",H1.city);
    printf("Enter the State");
    scanf("%s",H1.state);
    printf("Enter the pincode");
    scanf("%d",H1.pin);
    printf("The Address is:\n");
    printf("%s\n",H1.Name);
    printf("%s\n",H1.HN);
    printf("%s\n",H1.city);
    printf("%s\n",H1.state);
    printf("%d\n",H1.pin);
    return 0;
}
