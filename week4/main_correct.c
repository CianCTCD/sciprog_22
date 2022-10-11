#include <stdio.h>								//import relevant modules
#include <math.h>


float deg_to_rad(float theta)							//initialise the deg_rad function
{
	return M_PI*theta/180;
}

float trap_rule(float a , float b, int N, float function_array[N+1]){		//initialise trapezoidal function with a,b,N and the function array as parameters
										//a = start b = end N = steps 
	float sum = function_array[0] + function_array[N];
	int i = 0;								//i is the iterable
	for (i = 1;  i < N ; i++)						//loop through i
	{
		sum+= 2 * function_array[i];
	}	
	return (sum)* ((b - a)/(2*N));						//multiply the sum by the constant in the equation 
}	

int main(void){									//initialise our main function along with the various parameters 

	float start = 0;							
	float end = 60;
	int N =12;	
	float step_size = (end - start) / N;
	float tan_arr[N+1]; 							//we have one more point than twelve which is why we have N+1  
	int i = 0;	
	for ( i = 0 ; i <=N; i ++)
	{
		tan_arr[i] = tan(deg_to_rad(step_size*i));
		
	}
	float ans = trap_rule(deg_to_rad(start),deg_to_rad(end),N, tan_arr);	
	printf("ans is %f\n",ans);						//here we print our final answer
}


