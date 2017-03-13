#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letterAnalysis(char s[][80], int l);			   // prints a table indicating the number of occurrences of
													   // each letter of the alphabet in the complete text
int wordLengthAnalysis(char s[][80], int l, int len);  // returns the number of occurrences of words with
													   // that length appearing in the text
void wordAnalysis(char s[][80], int l);				   // prints a table indicating the number of occurrences 
													   // of each different word in the text

int main() {
	int num_lines;

	//scanf("%d", &num_lines);

	/*
	for (int i = 0; i < num_lines; i++) {
		scanf("%s", &story[i]);
	}

	for (int i = 0; i < num_lines; i++) {
		for (int j = 0; j < 80; j++) {
			int check = tolower(story[i][j]);
			printf("%c", story[i][j]);
		}
	}
	*/

	// Read story
	char line_char[10];
	fgets(line_char, 10, stdin);
	num_lines = line_char[0] - '0';  // If you have a character representing an integer, subtracting '0' returns the integer value of that character

	printf("%d\n", num_lines);

	char story[num_lines][80];

	for (int i = 0; i < num_lines; i++) {
		fgets(story[i], 80, stdin);  // Reads each line from the file into a row of the lines array
	}


	for (int i = 0; i < num_lines; i++) {
		for (int j = 0; j < 80; j++) {
			int check = tolower(story[i][j]);
			printf("%c", story[i][j]);
		}
	}

	printf("Total Letter Count:\n");
	letterAnalysis(story, num_lines);

	printf("\nWord Lengths:\n");
	for (int i = 1; i <= 20; i++) {
		printf("%2d word(s) of length %d\n", wordLengthAnalysis(story, num_lines, i), i);
	}

	return 0;
}

void letterAnalysis(char s[][80], int l) {
	// 97 - 122
	int let[26];

	for (int i = 97; i < 123; i++) {
		let[i - 97] = 0;
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < 80; j++) {
			int check = tolower(s[i][j]);
			if (check <= 122 && check >= 97) {
				let[check - 97]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%c: %-3d\n", (char)(i + 97), let[i]);
	}
}

int wordLengthAnalysis(char s[][80], int l, int len) {
	int tot = 0;

	for (int i = 0; i < l; i++) {
		char *pch = strtok(s[i], " ,.-");

		while (pch != NULL) {
			if (strlen(pch) == len) {
				tot++;
			}

			pch = strtok(NULL, " ,.-");
		}
	}

	return tot;
}

void wordAnalysis(char s[][80], int l) {
	int tot = 0;
	for (int i = 0; i < l; i++) {
		char *pch = strtok(s[i], " ,.-");

		while (pch != NULL) {
			if ((unsigned)strlen(pch) == 7) {
				tot++;
			}

			pch = strtok(NULL, " ,.-");
		}
	}
}