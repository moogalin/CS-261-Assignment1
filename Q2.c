
/* CS261- Assignment 1 - Q.2*/
/* Name: Megan Aldridge
* Date: April 10, 2016
* Solution description:
*	This program creates three integers and passes them by value or reference to a function.
*	The program displays the values of the integers before and after being passed into a function to demonstrate
*	both passing by value and passing by reference. 
*/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c) {
	/*Set a to double its original value*/
	*a = *a * 2;

	/*Set b to half its original value*/
	*b = *b / 2;

	/*Assign a+b to c*/
	c = *a + *b;

	/*Return c*/
	return c;
}

int main() {
	/*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;

	/*Print the values of x, y and z*/
	printf("The value of x is %d.\n", x);
	printf("The value of y is %d.\n", y);
	printf("The value of z is %d.\n\n", z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	int fooVal = foo(&x, &y, z);

	/*Print the value returned by foo*/
	printf("The value returned by foo is %d.\n\n", fooVal);

	/*Print the values of x, y and z again*/
	printf("The value of x is now %d.\n", x);
	printf("The value of y is now %d.\n", y);
	printf("The value of z is now %d.\n\n", z);


	/*Is the return value different than the value of z?  Why?
	*
	* Yes, the return value of the function foo is different than the value of variable 'Z'. 
	* Because 'Z' was passed by value to foo, a local copy of 'Z' was used within foo. 
	* Even though 'C' ('Z') was changed within foo, the changes were performed on the local copy, 
	* not on original variable 'Z'. Thus, the return value 'C' represents the changes made to the 'Z'
	* copy, but variable 'Z' carries the same integer value that it did before the call to foo. 
	*/

	return 0;
}


