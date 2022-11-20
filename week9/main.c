#include<stdio.h>
#include<stdlib.h>
#include "magic_square.h"
#define MAX_FILE_NAME 100


int get_num_lines(char filename[MAX_FILE_NAME])		//extract the number of lines from ou magic sqaure file 
{
	FILE *fp;
	fp = fopen(filename, "r");			//open the file
	int ch_read;
	int count = 0;
	while ((ch_read = fgetc(fp)) != EOF)		//we loop throug each line in the file and increment "count"
	{
		if(ch_read == '\n')
		{
			count++;
		}
	}
	printf("Number of lines id: %d\n", count);	//print the number of lines
	fclose(fp);
	return count;
}



int main(void)
{					
	FILE *f;		
	char filename[MAX_FILE_NAME];
	printf("Enter file name");
	scanf("%s", filename);

							//Retrieve the total number of lines  
	
	int n = get_num_lines(filename);
	
	f = fopen(filename, "r");			//open file


	int i;

	int **magicsquare = malloc(n*sizeof(int*)); 	//initialize dynamic array


	for(i = 0; i < n; i ++)
	{
		magicsquare[i] = malloc(n*sizeof(int));
	}



	int j;
	for(i = 0; i < n; i ++)
        {
		for(j = 0; j < n; j ++)
		{
			fscanf(f, "%d", &magicsquare[i][j]); //populate the array 
		}
	}
	int flag = isMagicSquare(magicsquare, n);
	if(flag == 1)
	{
		printf("This square is magic\n");
		
	}
	else
	{
		printf("This square is not magic \n");
	}
	for(i = 0; i < n; i++)
	{
		free(magicsquare[i]);			//free the array for better memory management 
	}
	free(magicsquare);
	fclose(f);					//closew the file
	return 0;
}
