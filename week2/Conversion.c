#include <stdio.h>
#include <math.h>

/* main function is required put void if you have absolutely no inputs*/
int main(void) {

/* Declare variables */
   int i,inum,tmp,numdigits;   //Declaring 4 interger variables gives 4 bites 
   float fnum;                 //float 4 bytes in memory 
   char binnum[60];            //char  = string in python [60] is generating an array. 60 = array size

/* Intialise 4-byte integer */
   inum = 33554431;            //we can initiaslise the variables 
/* Convert to 4-byte float */
   fnum = (float) inum;        //convert int to float "type casting"


/* Convert to binary number (string)*/
   i = 0; tmp = inum;          //process as referenced in notes how to convert base 10 to base 2 
   while (tmp > 0) {
     sprintf(&binnum[i],"%1d",tmp%2);
     tmp = tmp/2;
     i++;
   }

/* Terminate the string */
   binnum[i] = '\0';          //last element is always '\0'
       

/* Complete the expression */
   numdigits = ceil(logf(fnum)/logf(2));    //in C dont have log2 so  must use log e instead  ceil returns largest  integer nearest float
   printf("The number of digits is %d\n",numdigits);
    


   printf("inum=%d,  fnum=%f, inum in binary=%s\n",
      inum,fnum,binnum);

}
