/* works with all forms ,takes normal input ,converts to 3 column form, finds transpose, converts back to normal form */

#include<stdio.h>
#define max 101
struct sparse
{
	int row;
	int col;
	int value;
};
typedef struct sparse term;
int main()
{
	term s_mat[max],trans[max];
	int r,c,i,j;
	int a[20][20],b[20][20];
	printf("enter no of rows nd columns in matrix :");
	scanf("%d%d",&r,&c);
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("enter element (%d,%d) of matrix :",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}

	printf("input matrix is:\n");
	for (i=0;i<r;i++)	
	{
		for (j=0;j<c;j++)
		{
			 printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	int index = 1;
	s_mat[0].row = r;
	s_mat[0].col = c;
	s_mat[0].value = 0;

    	for (int i = 0; i < r; i++) 
	{
        	for (int j = 0; j < c; j++) 
		{
            		if (a[i][j] != 0) 
			{
                		s_mat[index].row = i;
               			s_mat[index].col = j;
                		s_mat[index].value = a[i][j];
                		index++;
                		s_mat[0].value++;
            		}
       		 }
    	}
	
	printf("\n3-Column Form:\n");
    	for (int i = 0; i <= s_mat[0].value; i++) 
	{
        	printf("%d %d %d\n", s_mat[i].row, s_mat[i].col, s_mat[i].value);
    	}

	trans[0].row = c;
    	trans[0].col = r;
    	trans[0].value = s_mat[0].value;

	for (int j = 0; j < c ; j++) 
	{
        	for (int i = 1; i <= s_mat[0].value; i++)  //putting i=1 nd i=0 gives same output, why?
		{
            		if (s_mat[i].col == j) 
			{
                		trans[i].row = s_mat[i].col;
                		trans[i].col = s_mat[i].row;
                		trans[i].value = s_mat[i].value;
           	 	}
        	}
    	}

	printf("transpose is:\n");
	for (int i = 0; i <= trans[0].value; i++) 
	{
        	printf("%d %d %d\n", trans[i].row, trans[i].col, trans[i].value);
    	}

	printf("Transpose in Normal Form:\n");
    	for (int i = 0; i < c; i++) 
	{
        	for (int j = 0; j < r; j++) 
		{
            		b[i][j] = 0;
            		for (int k = 0; k <= trans[0].value; k++) 
			{
                		b[trans[k].row][trans[k].col]=trans[k].value;
            		}
            		printf("%d ", b[i][j]); 
       		}
        	printf("\n");
	}
	return(0);
}


	