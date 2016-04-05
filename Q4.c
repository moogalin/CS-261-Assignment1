
/* CS261- Assignment 1 - Q.4*/
/* Name:
* Date:
* Solution description:
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

void sort(struct student* students, int n) {
	/*Sort the n students based on their score*/

	/* Using bubble sort */
	for (int i = 0; i < (n - 1); i++)
		for (int j = 0; j < (n - i - 1); j++) {
			if (students[j].score > students[j + 1].score) {
				int tempScore = students[j].score;
				int tempID = students[j].id;
				students[j].score = students[j + 1].score;
				students[j].id = students[j + 1].id;
				students[j + 1].score = tempScore;
				students[j + 1].id = tempID;
			}
		}
}

int main() {
	/*Declare an integer n and assign it a value.*/
	int n = 10;

	/*Allocate memory for n students using malloc.*/
	struct student * students;
	students = malloc(n* sizeof(struct student));

	/*Generate random IDs and scores for the n students, using rand().*/
	int arrIDs[10];
	int arrScores[100];
	int randID;
	int randScore;
	int unique = 0;	// bool variable to ensure ID and score is unique

	/* Generate array of possible IDs*/
	for (int i = 0; i < 10; i++) {
		arrIDs[i] = i + 1;
	}

	/* Generate array of possible Scores*/
	for (int i = 0; i < 100; i++) {
		arrScores[i] = i + 1;
	}


	for (int i = 0; i < n; i++) {

		/* At least once, generate random number for ID*/
		do {
			randID = rand() % 10 + 1;

			if (arrIDs[randID - 1]) { /* If random number is in array, then ID is unique */
				students[i].id = randID;
				arrIDs[randID - 1] = 0;	/* Remove assigned ID from array */
				unique = 1;
			}
			else {
				unique = 0;
			}
		} while (!unique); /* Unique ID generated for given student */

		/* Generate random score for student (not unique) */
		randScore = rand() % 100 + 1;
		students[i].score = randScore;

		/* For next iteration of loop, ensure that unique flag is not set*/
		unique = 0;

	}

	/*Print the contents of the array of n students.*/
	printf("Before sorting:\n");

	for (int i = 0; i < 10; i++) {
		printf("ID: %d Score: %d\n", students[i].id, students[i].score);
	}

	/*Pass this array along with n to the sort() function*/
	sort(students, n);

	/*Print the contents of the array of n students.*/
	printf("\nAfter sorting:\n");

	for (int i = 0; i < 10; i++) {
		printf("ID: %d Score: %d\n", students[i].id, students[i].score);
	}
	
	return 0;
}
