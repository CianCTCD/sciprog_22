#include<stdio.h>
#include<stdlib.h>


//we wont return anything we will access their through their locations in memmory 
//on exit they have values of fn and fn-1
void fibonacci(int *a, int *b);								//declare function with no return pointers as inputs 





int main(void)										//initialise the main function
{

	int n, i;									//i is a counter n is our input, it decides how many terms in the sequence are printed 
	int f1 =1, f0 = 0;
	
	printf("Enter positive integer n\n");
	scanf("%d", &n);								//we take an integer input 
	
	if(n<1)										//if statement prints a warning if n <1
	{
		printf("The number is not positive\n");
		exit(1);								// Note to self: import stdlib.h to use the exit function. 
	}
	printf("The fibonacci sequence is: \n");					// print first two terms 0 and 1
	printf("%d, %d, ", f0, f1);

	for(i =2; i<=n; i++)								// this for loop breaks when we have printed the specified number of terms in the loop. 
	{
	
		fibonacci(&f1, &f0);							// we call our fibanacci function
		printf("%d, ", f1);							
		if (((i+1)%10) ==0) printf("\n");					//when we get to the end of our loop we print a new line 	
	
	}


	return 0;									//return 0 --> success
}



void fibonacci(int *a, int *b){								//here is our fibonacci function, we initialised it at the top of our script.

	int next;
	
	next = *a + *b;									//*a = f(n-1)		*b = f(n-2)		next = f(n)
	*b = *a;									//*b= f(n-1)
	*a = next;
	
}
