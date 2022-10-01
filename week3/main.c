#include <stdio.h>
#include <math.h>
int main() {
	/*Declaration of Variables*/
	int i = 0; 								//counter 
	float a = 0, b = 1.047197551, Num_points = 13.0, N = Num_points - 1;    //inputs for the calculation, a/b = bounds, Num_points = ALL points INCLUDING!!! a and b 
	float  y = 0, division = 0, area = 0, point = 0 , second_point = 0;	//Various variable required in the function below 



	int area_under_func() {							//intialise our area calculating function
		division = (b-a)/(Num_points - 1);				//we calculate the size of the spaces between points 
		area = tan(a) - tan(b);						//tan(a) and tan(b) form the first contribution to the total area 
		for (i = 0; i <= Num_points -2; ++i){				//The ceiling is Num_points - 2 to avoid double counting the point at the outer bound "b"
			second_point = a + division;				//We start at the second point to avoid double counting at the point x = a (inner bound)
			point = (second_point+(division*i));			//we calculate essentially the x value which will form our input for the trapezoidal method
			area = area + (2*tan(point));				//we use this point (x value) to calculate a contribution (term) to the overall area 
			
		}
		area = area * ((b-a)/(2*N));					//we then multiply by the constent 
		printf("Area   =  %5f\n",area);					//print the final area 
		
		
	
	}
	area_under_func();							//call the above function
	printf("log(2) =  %3f\n",log(2.0));
	return 0;
}
