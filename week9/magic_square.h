

int isMagicSquare(int **square, const int n)
{
	if (n < 0)	
	{
		return 0;
	}
	
	int magic_num = 0;
	int off_diag_sum = 0;
	int i, j;

	for(i = 0; i < n; i++)
	{
		magic_num+=square[i][i];			//evaluate what the magic number should be
		off_diag_sum+=square[i][n - i - 1];		//retrieve off diagonal sum
	}
	if (off_diag_sum != magic_num)				//we enter this loop if we do not have a magic square 
	{
		printf("off_diag equals %d and magic_num equals %d\n", off_diag_sum, magic_num);
		printf("The off_diag is not the same as the diag\n");
		return 0;
	}
	for (i = 0; i < n; i ++)
	{
		int rowSum = 0;					//initialise row and coumn sum 
		int colSum = 0;
		for (j = 0; j < n; j ++)
		{	
			rowSum += square[i][j];
			colSum += square[j][i];
		}
		if(rowSum != magic_num || colSum != magic_num)	//if row sum OR column sum are not equal to the agic number. 
		{
			printf("rowSum or colSum isn't equal to magic_num\n");
			return 0;
		}

	return 1;
	}
} 
