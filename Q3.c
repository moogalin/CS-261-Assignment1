
/* CS261- Assignment 1 - Q.3*/
/* Name: Megan Aldridge
* Date: April 10, 2016
* Solution description:
*	This program allocates a dynamic array of 20 integers, fills the array with random integers
*	in the range of 1 to 100, displays the array, sorts the array, 
*	and then displays the sorted array. 
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n) {
	/*Sort the given array number , of length n*/

	/* Using bubble sort */
	for (int i = 0; i < (n - 1); i++)
		for (int j = 0; j < (n - i - 1); j++) {
			if (number[j] > number[j + 1]) {
				int temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
}


int main() {
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;

	/*Allocate memory for an array of n integers using malloc.*/
	int * pArray;
	pArray = (int *)malloc(n * sizeof(int));

	/*Fill this array with random numbers, using rand().*/

	for (int i = 0; i < (n); i++) {
		pArray[i] = (rand() % 100 + 1);
	}

	/*Print the contents of the array.*/
	printf("\nBefore sorting, the contents of the array are as follows:\n");
	for (int i = 0; i < (n); i++) {
		printf("Array[%d]= %d\n", i, pArray[i]);
	}

	/*Pass this array along with n to the sort() function of part a.*/
	sort(pArray, n);

	/*Print the contents of the array.*/
	printf("\nAfter sorting, the contents of the array are as follows:\n");
	for (int i = 0; i < n; i++) {
		printf("Array[%d]= %d\n", i, pArray[i]);
	}



	return 0;
}
