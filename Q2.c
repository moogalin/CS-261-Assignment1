
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
	int fooVal = foo(&x, &y, &z);

	/*Print the value returned by foo*/
	printf("The value returned by foo is %d.\n\n", fooVal);

	/*Print the values of x, y and z again*/
	printf("The value of x is now %d.\n", x);
	printf("The value of y is now %d.\n", y);
	printf("The value of z is now %d.\n\n", z);


	/*Is the return value different than the value of z?  Why?*/
	printf("The return value is different for x and y but not z.\n");
	printf("This is because x and y were passed by reference and changed within the foo function.\n");
	printf("They were changed because foo had access to their real memory location.\n");
	printf("The value of z was not changed because z was passed by value and only a copy of z could be changed in foo.");

	return 0;
}


