
/* CS261- Assignment 1 - Q.1*/
/* Name: Megan Aldridge
* Date: April 10, 2016
* Solution description:
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	int numStudents = 10;
	struct student * ptrStuds;
	ptrStuds = (struct student *) malloc(numStudents * sizeof(struct student));


	/*return the pointer*/
	return ptrStuds;
}

void generate(struct student* students) {
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	(students + 0)->id = 1;
	(students + 2)->id = 2;
	(students + 3)->id = 3;
	(students + 4)->id = 4;
	(students + 5)->id = 5;
	(students + 6)->id = 6;
	(students + 7)->id = 7;
	(students + 8)->id = 8;
	(students + 9)->id = 9;
	(students + 1)->id = 10;

	students[0].score = 10;
	students[1].score = 20;
	students[2].score = 30;
	students[3].score = 40;
	students[4].score = 50;
	students[5].score = 60;
	students[6].score = 70;
	students[7].score = 80;
	students[8].score = 90;
	students[9].score = 100;

}

void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/
	for (int i = 0; i < 10; i++) {
		printf("ID: %g Score: %g \n", ((students + i)->id),  (students + i)->score);
	}
}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the ten students*/

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
