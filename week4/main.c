#include <stdio.h>
#include <math.h>

int main() {
        /*Declaration of Variables*/
        int i = 0;                                                              //counter 
        float a = 0, b = 1.047197551, Num_points = 13.0, N = Num_points - 1;    //inputs for the calculation, a/b = bounds, Num_points = ALL points INCLUDING!!! a and b 
        float  y = 0, division = 0, area = 0, point = 0 , second_point = 0;     //Various variable required in the function below  
	float argument;
		
	float degree_to_radians(argument) {					//Here we initialise our function for converting degrees to radians 
		float rad;
		rad = argument*(M_PI/180.0);					
		printf("float 'rad' from degree_to_radians function   =  %5f\n",rad);
		return rad;
	}

	
	float angle_iterator() {
		int arr[13] = {0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0};                             //An array of degree angles to be iterated over. 
	        int j = 0;                                                              //for iterating
		int arrLen = sizeof arr / sizeof arr[0];                                //array lenght --> https://www.tutorialkart.com/c-programming/c-iterate-over-array-using-while-loop/#:~:text=C%20%E2%80%93%20Iterate%20over%20Array%20using,access%20the%20element%20using%20index
		float rad_it;                                                           //radians variable in iterator function
        	int arr_tan[13];
       		float tan_val;
        	float var_it;
		while ( j < 13){
			printf("'j' the iterator from the angle_iterator function   =  %5f\n",j);
			rad_it = degree_to_radians(arr[j]);				//convert degrees to radians 
			tan_val = tan(rad_it);
			printf("arr[j] the j-th element of the array   =  %5f\n",arr[j]);
			arr_tan[j] = tan_val;
			printf("arr_tan[j] the appended variable to the empty output array  %d\n", arr_tan[j]);
			printf("   \n");
			printf("   \n");
			j++;
		} 
	}


        int area_under_func() {                                                 //intialise our area calculating function
                division = (b-a)/(Num_points - 1);                              //we calculate the size of the spaces between points 
                area = tan(a) - tan(b);                                         //tan(a) and tan(b) form the first contribution to the total area 
                for (i = 0; i <= Num_points -2; ++i){                           //The ceiling is Num_points - 2 to avoid double counting the point at the outer bound "b"
                        second_point = a + division;                            //We start at the second point to avoid double counting at the point x = a (inner bound)
                        point = (second_point+(division*i));                    //we calculate essentially the x value which will form our input for the trapezoidal method
                        area = area + (2*tan(point));                           //we use this point (x value) to calculate a contribution (term) to the overall area 

                }
                area = area * ((b-a)/(2*N));                                    //we then multiply by the constent 
                printf("Area   =  %5f\n",area);                                 //print the final area 



        }
        area_under_func();                                                      //call the above function
	printf("log(2) =  %3f\n",log(2.0));
	angle_iterator();
        return 0;
}

