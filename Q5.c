
/* CS261- Assignment 1 - Q.5*/
/* Name: Megan Aldridge
* Date: April 10, 2016
* Solution description:
*	This program receives a single word (character string without spaces) from standard input and outputs the 
*	equivalent word with "sticky caps" (alternating uppercase and lowercase). 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
	return ch - 'a' + 'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
	return ch - 'A' + 'a';
}

void sticky(char* word) {
	/*Convert to sticky caps*/
	int i = 0;

	while (word[i] > '\0'){
		if (i % 2 == 0) { // Even letter in word, will be uppercase

			if (word[i] > 'a') {	// Convert to uppercase, if currently lowercase

				word[i] = toUpperCase(word[i]);
			}

		}

		else if (i % 2 == 1) { // Odd letter in word, will be lowercase

			if (word[i] < 'a') {	// Convert to lowercase, if currently uppercase 

				word[i] = toLowerCase(word[i]);
			}
		}
		i++;
	}
	
}

int main() {
	/*Read word from the keyboard using scanf*/
	char stickyWord[MAX_SIZE];
	char *ptrWord;
	ptrWord = stickyWord;
	printf("Enter word: ");
	scanf("%s", stickyWord);

	/*Call sticky*/
	sticky(ptrWord);
	
	/*Print the new word*/
	printf("Your new \"sticky caps\" word is: %s\n", stickyWord);


	return 0;
}
