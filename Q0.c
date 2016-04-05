
/* CS261- Assignment 1 - Q. 0*/
/* Name: Megan Aldridge
* Date: April 10, 2016
* Solution description: 
*	This program demonstrates how pointers work in the C programming language.
*	Namely, this program shows that pointers point to the addresses of variables,
*	can be dereferenced to access the values at specific addresses, and can be passed
*	to functions to allow variables to be accessed by reference. 
*/

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr) {
	/*Print the value pointed to by iptr*/
	printf("The value pointed to by 'iptr' is %d \n", (*iptr));

	/*Print the address pointed to by iptr*/
	printf("The address pointed to by 'iptr' is %p \n", (iptr));

	/*Print the address of iptr itself*/
	printf("The address of 'iptr' itself is %p \n", (&iptr));
}

int main() {

	/*declare an integer x*/
	int x = 5;

	/*print the address of x*/
	printf("The address of 'x' is %p \n", &x);

	/*Call fooA() with the address of x*/
	fooA(&x);

	/*print the value of x*/
	printf("The value of 'x' is %d \n", x);


	return 0;
}
