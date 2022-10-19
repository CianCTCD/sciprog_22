#include<stdio.h>
#include<math.h>


double arctanh1(const double x, const double delta);								//we initialise our function for the Maclaurin series. 

double arctanh2(const double x);										//we initialise our function for the natural logarithm method 

int main(void)													//main function
{				
	double delta, x;											//intialise variables as doubles --> high percision 
	
	printf("Enter the percision for Maclaurin series\n");							
	scanf("%lf", &delta);											//This determines how many terms in the Maclaurin series
	printf("delta is : %lf \n ", &delta);
	int lenght = 1000;											//the lenght of our list is large to ensure we have enough memory allocated for all the ellements of the list. 
	double tan1[lenght]; 											//Store the results of arcTanh1 for each x						
	double tan2[lenght]; 											//Store the results of arcTanh2 for each x
	
	int j = 0; 												//array index
	x = -0.9;
	while (x<=0.9 && j < lenght)
	{
		tan1[j] = arctanh1(x,delta);									//here we append our list with the values from arctanh1
		tan2[j] = arctanh2(x);										//similarly we append our list
		printf("tan1[j] is : %lf \n ",tan1[j]);								//these were print statements that I added to debug the code. 
		printf("tan2[j] is : %lf \n ",tan2[j]);
		printf("the difference at x = %lf between them is %.10lf\n", x,fabs(tan1[j]-tan2[j]));		//we print the difference between the two methods 
		j++;												//increment 
		x = x+0.1; 											//we can also increment x
	}

	return 0;
}



double arctanh1(const double x, const double delta)								//This is our first function which contains the method for the Maclaurin series 
{	
	double arcTan =0; 											// approximated result
	double elem, val;
	int n = 0; 												//sum parameter
	do {
		val = 2*n+1;
		elem = pow(x,val)/val;
		arcTan +=elem;
		n++;
	
	} while(fabs(elem) >= delta); 										//fabs return absolute value. we run the above code until the absolute value of elem is >= to delta
	
	return arcTan;												//we return our arcTan double percision veriable 
	
}






double arctanh2(const double x)
{
	return((log(1.0+x)-log(1.0-x))/2.0);									//Here we use the formula as an alternative to the Maclauirn series.
														//OBSERVATIONS: it was noted that decreaseing the value of delta decreased the difference between the two methods. 
}														//This is due to the improvemnent of the accuracy o the Maclaurin series. 
