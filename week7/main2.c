#include<stdio.h>
#include<math.h>
#include<stdlib.h>


//Allocate array
int *allocatearray(int n)					//* means it takes pointer as input i
{
	int *p;							//intialise temporary pointer 
	p = (int *) malloc((n)*sizeof(int));			//we set up our array where we multiply the number of ints we want in our array by the lenght of an integer
	if(p == NULL){printf("Error in allocating memory\n");}	//To catch errors
	return p;						// return our pointer 

}				
	
//Fill with ones (array as input)
void fillwithones(int *array, int n)
{
	int i;							//initialise the counter 
	for(i = 0; i<n; i++)					//we assign each term in our array to be 1
	{
		array[i] = 1; 
	}
}

//print the array
void printarray(int *array, int n)
{
	int i;
	for(i =0; i < n; i++)
	{
		printf("a[%d]=%d\n", i, array[i]);		//Here we print out each term of the array with the index in square brackets
	}
}


//Deallocate the array 
void freearray(int *array)
{
	free(array); 						//free up memory to prevent memory leaks 
}


int main(void)
{
	int lenght, *a;						//intialise the lenght of the array and a pointer 
	printf("Size of the array? --> \n");			//input the size of the desired array 
	scanf("%d", &lenght);

	a=allocatearray(lenght); 				//a points to the location of an array with a lenght "lenght"
	fillwithones(a, lenght);				//update array to contain all ones 
	printarray(a, lenght);					//we print the array 
	freearray(a);						//free up allocated memory 
	a = NULL;



return 0;
}								// end main

