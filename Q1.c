
/* CS261- Assignment 1 - Q.1*/
/* Name: Megan Aldridge
* Date: April 10, 2016
* Solution description:
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM_STUDENTS 10

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	struct student * students = malloc(NUM_STUDENTS * sizeof(struct student));

	/*return the pointer*/
	return students;

}

void generate(struct student* students) {
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
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


	for (int i = 0; i < NUM_STUDENTS; i++) {

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
}

void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/

	for (int i = 0; i < NUM_STUDENTS; i++) {
		printf("%d %d \n", students[i].id, students[i].score);
	}

}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the ten students*/

	/* Compute Minimum and Maximum */

	int smallest = students[0].score;
	int largest = students[0].score;
	int sum = 0;
	int average;

	for (int i = 0; i < NUM_STUDENTS; i++) {

		if (students[i].score < smallest) {
			smallest = students[i].score;
		}

		if (students[i].score > largest) {
			largest = students[i].score;
		}

		sum += students[i].score;
	}

	/* Compute Average */
	average = sum / NUM_STUDENTS;


	/* Print Minimum, Maximum, and Average */
	printf("The minimum score is %d\n", smallest);
	printf("The maximum score is %d\n", largest);
	printf("The average score is %d\n", average);

}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	free(stud);
}

int main() {
	struct student* stud = NULL;

	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);

	/*call output*/
	output(stud);

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	deallocate(stud);


	return 0;
}
