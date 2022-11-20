#include<stdlib.h>
#include<stdio.h>

void hanoi(int n, int source, int destination, int inter)
{
	//base case
	if(n ==	1)								//n = the number of discs, source = the source rod and destination, destination = destination rod, inter = interim rod bewtween the other rods 
	{
		printf("Move disc %d to %d \n", source, destination);		// only if we have one disc
	}
	else
	{
		hanoi(n-1 ,source, inter, destination);				// use 3 as intermediary
		printf("move disc from %d to %d \n", source, destination);	//command for how to move discs 
		hanoi(n-1, inter, destination, source);				// move from rod 2 to 3 using rod 1 as the intermediary. 
	}
	


}

int main(void)

{	
	int h =2;
	printf("Solution for %d discs\n",h);
	hanoi(h,1,2,3);   							//call the function 
	return 0;
}
