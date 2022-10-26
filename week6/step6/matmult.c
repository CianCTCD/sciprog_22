#include<stdio.h>

void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]){
	
	int i, j, k;
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
}
