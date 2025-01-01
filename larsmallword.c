#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100][100],s[50],l[50];
	int k=0,i,j,m=0;
	printf("enter string:");
	fgets(a,sizeof(a),stdin);
	for (i=0;i<strlen(a);i++)
	{
		if (a[i]!=' ')
		{
			b[k][m]=a[i];
			m++;
		}
		else if (a[i]==' ')
		{
			k++;
			m=0;
		}	
	}
	for (i=0;i<k;i++)
 	{
		for(j=0;j<m;j++)
		{
			printf("%s",b[k][m]);
		}
		printf("\n");
	}
	return(0);
}
