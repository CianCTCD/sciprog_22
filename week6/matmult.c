#include<stdio.h>

int main(void)
{								
	int n=5, p=3, q=4;				//array dimensions
	double A[n][p], B[p][q], C[n][q]; 		//static array --> cannot change size --> located in stack
	int i, j, k;					//counters
	
	for(i=0; i<n; i++)				//A --> we ensure the counters do not extend beyond the bounds of the static array 
	{
		for(j=0; j<p; j++)
		{
			A[i][j] = i+j;			//A is defined as the sum of the indexes 
		}		


	}

			
	for(i=0; i<p; i++)				//B --> i<p and j<q for the same reason as above, we are dealing with static arrays 
        {
                for(j=0; j<q; j++)      
                {
                        B[i][j] = i-j;			//B is defined as the difference between the indexes 
                }


        }


	for(i=0; i<n; i++)				//C
        {
                for(j=0; j<q; j++)      
                {
                        C[i][j] =0.0;			//C is initialised with zero in every entry.
                }


        }
	


	//Matrix Multiplication
	for(i=0; i <n; i++)				//Here we must iterate all entrys in A and B 
	{
		for(j=0; j<q; j++)
		{
			for(k = 0; k<p; k++)
			{
			C[i][j] = C[i][j]+A[i][k]*B[k][j];	//Here we update C with the A_ij times B_ij 
			}
		}
	}


	//print
	printf("\nThis is Matrix A: \n");		//In the following section we loop through all the entries of the 'input' matrices (A and B) and 
	for(i=0; i<n; i++)				//and the 'output' matrix C.
	{						//we ensure that the for loops do not extend beyond the dimension of the matrix by statng that 
		for(j=0; j<p; j++)			//i<n and j<p for matrix A. Similar limits are placed on the for loops for the matrices A and B 
		{
			printf("%3.0f ",A[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nThis is Matrix B: \n");
        for(i=0; i<p; i++)
        {
                for(j=0; j<q; j++)
                {
                        printf("%3.0f ",B[i][j]);
                }
                printf("\n");
        }

	printf("\nThis is Matrix C: \n");
        for(i=0; i<n; i++)
        {
                for(j=0; j<q; j++)
                {
                        printf("%3.0f ",C[i][j]);
                }
                printf("\n");
        }
return 0;
}
