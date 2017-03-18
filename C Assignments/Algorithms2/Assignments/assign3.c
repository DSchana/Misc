/*
 * Title:	assign3.c
 * Author:	Dilpreet S. Chana
 * Description:	Text analyzer that shows various details
 *		about a given text.
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letterAnalysis(char s[][80], int l);	       // prints a table indicating the number of occurrences of
						       // each letter of the alphabet in the complete text
int wordLengthAnalysis(char s[][80], int l, int len);  // returns the number of occurrences of words with
						       // that length appearing in the text
void wordAnalysis(char s[][80], int l);                // prints a table indicating the number of occurrences 
						       // of each different word in the text

int main() {
	int num_lines = 0;

	scanf("%d", &num_lines);

	char story[10][80] = { { 0 } };

	// Read story 
	for (int i = 0; i <= num_lines; i++) {
		fgets(story[i], 80, stdin);  // Reads each line from the file into a row of the lines array
	}

	printf("Total Letter Count:\n");
	letterAnalysis(story, num_lines);

	printf("\nWord Lengths:\n");
	for (int i = 1; i <= 20; i++) {
		int w_len = wordLengthAnalysis(story, num_lines, i);

		if (w_len == 1) {
			printf("%2d word of length %d\n", w_len, i);
		}
		else {
			printf("%2d words of length %d\n", w_len, i);
		}
	}

	printf("Word Frequencies:\n");
	wordAnalysis(story, num_lines);

	return 0;
}

/*
 * Description:	Display the frequency of each letter
 * Parameters:	2d array: The text to analyze
 *		Integer: Number of lines in text
 * Returns:	void
**/
void letterAnalysis(char s[][80], int l) {
	// 97 - 122
	int let[26] = { 0 };

	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < 80; j++) {
			if (isalpha(s[i][j])) {
				char curr = tolower(s[i][j]);
				let[curr - 'a']++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%c: %-3d\n", (char)(i + 97), let[i]);
	}
}

/*
 * Description: Count the number of words with a specified length
 * Parameters:  2d array: The text to analyze
 *              Integer l: Number of lines in text
 *		Integer len: Target word size
 * Returns:     Number of words with length len
**/
int wordLengthAnalysis(char s[][80], int l, int len) {
	int tot = 0;

	for (int i = 1; i <= l; i++) {
		int curr_len = 0;
		for (int j = 0; j < 80; j++) {
			if (!isblank(s[i][j] && s[i][j] != 0 && !iscntrl(s[i][j]))) {
				curr_len++;
			}
			else if (s[i][j] == 0 || isblank(s[i][j])) {
				if (curr_len == len) {
					tot++;
				}

				curr_len = 0;
			}
		}
	}

	return tot;
}

/*
 * Description: Display the frequency of each word
 * Parameters:  2d array: The text to analyze
 *              Integer: Number of lines in text
 * Returns:     void
**/
void wordAnalysis(char s[][80], int l) {
	char s_copy[10][80];
	char *tkn;

	int word_count = 0;
	int largest = 0;

	for (int i = 0; i < 10; i++) {
		strcpy(s_copy[i], s[i]);
	}

	for (int i = 1; i <= l; i++) {
		tkn = strtok(s[i], " \n\r\b\t");

		while (tkn != NULL) {
			word_count++;
			tkn = strtok(NULL, " \n\r\b\t");
		}
	}

	char words[word_count][20];
	int word_freq[word_count];
	int word_pos = 0;

	memset(words, 0, sizeof(words[0][0]) * word_count * 20);
	memset(word_freq, 0, sizeof(word_freq[0]) * word_count);

	// Fill the words array
	for (int i = 1; i < l; i++) {
		tkn = strtok(NULL, " \n\r\b\t");

		while (tkn != NULL) {
			strcpy(words[word_pos], tkn);

			word_pos++;
			tkn = strtok(NULL, " \n\r\b\t");
		}
	}

	// Count frequencies
	for (int i = 0; i < word_count; i++) {
		if (strcmp(words[i], " ") != 0) {
			for (int j = i; j < word_count; j++) {
				if (strcmp(words[i], words[j]) == 0) {
					word_freq[i]++;
					if (i != j) {
						strcpy(words[j], " ");  // Mark as analyzed
					}
				}
			}
		}
	}

	// Find largest word size
	for (int i = 0; i < word_count; i++) {
		int curr_len = 0;
		for (int j = 0; j < 20; j++) {
			if (words[i][j] != 0) {
				curr_len++;
			}
		}

		if (curr_len > largest) {
			largest = curr_len;
		}
	}

	// Print table
	for (int i = 0; i < word_count; i++) {
		if (word_freq[i] > 0) {
			printf("\"%s\"", words[i]);
			for (int j = 0; j < largest - strlen(words[i]); j++) {
				printf(" ");
			}

			if (word_freq[i] == 1) {
				printf(" appeared 1 time\n");
			}
			else {
				printf(" appeared %d times\n", word_freq[i]);
			}
		}
	}
}
