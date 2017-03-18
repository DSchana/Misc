/*
 * Title:	lab7b.c
 * Author:	Dilpreet S. Chana
 * Description: Demonstration of the abstract string
 * 		struct Word.
**/

#include <stdio.h>
#include <string.h>

struct Word {
	char word[21];
	int len;
};

int main() {
	struct Word word_list[20];
	char *tok;
	int pos = 0;

	char myString[] = "the cat in the hat jumped over the lazy fox";

	tok = strtok(myString, " ");

	while (tok != NULL){
		strcpy(word_list[pos].word, tok);
		word_list[pos].len = strlen(word_list[pos].word);
		pos++;

		tok = strtok(NULL, " ");
	}

	for (int i = 0; i < pos; i++){
		printf("Word: %s Length: %d\n", word_list[i].word, word_list[i].len);
	}

	// sort
	for (int i = 0; i < pos - 1; i++){
		for (int j = 0; j < pos - i - 1; j++){
			if (strcmp(word_list[j].word, word_list[j + 1].word) > 0){
				struct Word temp = word_list[j];
				word_list[j] = word_list[j + 1];
				word_list[j + 1] = temp;
			}
		}
	}

	printf("\n");

	for (int i = 0; i < pos; i++){
		printf("Word: %s Length: %d\n", word_list[i].word, word_list[i].len);
	}
}
