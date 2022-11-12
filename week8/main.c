#include<stdio.h>


//Greatest Common Divisor --> Euclid's Algorithm

int iterativeGCD(int a, int b);							//Here we initialise our functions 
int recursiveGCD(int a, int b);

int main(void)									//main function, this is the start of the program 
{	
	int a, b, ierror;							//Initialise our two inputs and our "error-catching variable"
	printf("Please input two positive whole integers:\n");
	ierror = scanf("%d %d", &a, &b);
	if(ierror !=2)								//If we haven't inputed two variables. 
	{
		printf("Only input 2 integers\n");
		return 1;
	} 
	
	if(a<=0 || b <= 0)
	{
		printf("These numbers are not positve!!!!!!\n");
		return 1;
	}

	//Call functions 
	printf("IterativeGCD(%d, %d)=%d\n",a ,b, iterativeGCD(a, b));
	printf("RecursiveGCD(%d, %d)=%d\n",a ,b, recursiveGCD(a, b));
return 0;
}


int iterativeGCD(int a, int b)
{
	int temp;								//we initailise our temporary variable 
	while(b != 0)								//while the remainder is not 0
	{
		temp = b;							//set temporary variable = to b 
		b=a%b;								//modulo operator (remainder after division)
		a=temp;
	}
	return a;
}


int recursiveGCD(int a, int b)
{
	if(b == 0)								//if b is 0 then we return the value a 
	{
		return a;							
	}
	else
	{	
		return(recursiveGCD(b, a%b));					//otherwise we call the function again with b and the remainder of a/b as arguments.
	}
}


