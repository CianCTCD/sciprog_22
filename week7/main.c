/* Find e using Taylor expansion*/
#include<stdio.h>									//import stdio
#include<math.h>									//we will use exp function
#include<stdlib.h>									//This so we can use malloc 


int factorial (int n);									//intialise function which takes integer as an argument 

int main(void)										//initialise main function 
{	
	int i, order;									//i is the loop counter and order gives the order of the polynomial 
	double e, *terms; 								// e --> for the sum   *terms --> pointer to array
	
	//Enter polynomial order
	printf("Enter Polynomial\n");							//asks user to input desired order 
	if (scanf("%d",&order) != 1)							//scan for user input put input in memory location of order.  %d for int.	
	{
		printf("you did not enter a number");					//print error message 
		return 1;								// return 1
	}
	
	//Allocate space for terms array
	terms = malloc(order*sizeof(double));						//each term in the array will be assigned size double. multiply this by r-value @ order to get   
	for(i = 0; i < order; i++)							//size of the array. 
	{
		terms[i] = 1.0/(double)factorial(i+1);					//construct each term of the array 
		printf("e term for order %d is %1.14lf\n",order, terms[i]); 		//14 places after the decimal place and print out every term 
	}

	e = 1.0;									//initialise e with the first term before we carry out the summation 
	
	for(i =0; i < order; i++)							//construct sum 
	{
		e = e + terms[i];
	}
	
	free(terms);									//takes pointer to remove memory allocation  

	printf("\ne is estimated as %.10lf. with difference %.10lf. \n", e , e-exp(1.0));	// prints difference in approsimate and "exact value"

return 0;										
}


int factorial(int n)									//initalise our factorial function
{	
	if (n<0)									//error detection 
	{
		printf("Error should be +");
		return -1;
	}
	
	else if(n==0)
	{
		return 1;
	}

	else		
	{
		return (n*factorial(n-1));						//function calls itself, recursive fuction 
	}
}

//Observation --> reason for lack of decrease in higher order polynomials is int can't hold numbers larger than 13! factorial. 
