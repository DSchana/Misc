/*
 * Title:	lab7a.c
 * Author:	Dilpreet S. Chana
 * Description:	Manual implementation of some
 *		string manipulation meathods.
**/

#include <math.h>
#include <stdio.h>

int AtoI(const char *str);
int strCmp(const char *str1, const char *str2);
char *strCpy(char *dst, const char *src);
char *strCat(char *dst, const char *src);
char *strChr(char *str, int c);

int main() {
	char str1[] = "apples";
	char str2[] = "applse";
	char str3[15];
	char num[] = "56";

	printf("AtoI: %d\n", AtoI(num));
	printf("Cmp:  %d\n", strCmp(str1, str2));
	strCpy(str3, str1);
	printf("Cpy:  %s\n", str3);
	strCat(str3, str2);
	printf("Cat:  %s\n", str3);
	printf("Chr:  %c at %p\n", 'l', strChr(str1, (int)'l'));

	return 0;
}

/*
 * Description:	Convert string representing an integer
 *		to the integer.
 * Parameters:	Pointer to char array - str1: String containing integer
 * Returns:	Interger represented in str1
**/
int AtoI(const char *str) {
	int num = 0;
	int len;

	for (len = 0; *(str + len) != '\0'; len++);
	for (int i = 0; *(str + i) != '\0'; i++) {
		num += (*(str + i) - '0') * pow(10, len - i - 1);
	}

	return num;
}

/*
 * Description:	Compare two strings.
**/
int strCmp(const char *str1, const char *str2) {
	for (int i = 0; *(str1 + i) != '\0' || *(str2 + i) != '\0'; i++) {
		int diff = *(str1 + i) - *(str2 + i);

		if (diff != 0) {
			return diff;
		}
	}
	return 0;
}

char *strCpy(char *dst, const char *src) {
	int i;

	for (i = 0; *(src + i) != '\0'; i++) {
		*(dst + i) = *(src + i);
	}

	*(dst + i + 1) = '\0';

	return dst;
}

char *strCat(char *dst, const char *src) {
	int i, j;
	for (i = 0; *(dst + i) != '\0'; i++);
	for (j = 0; *(src + j) != '\0'; j++) {
		*(dst + i + j) = *(src + j);
	}

	*(dst + i + j + 1) = '\0';

	return dst;
}

char *strChr(char *str, int c) {
	for (int i = 0; *(str + i) != '\0'; i++) {
		if ((int)*(str + i) == c) {
			return (str + i);
		}
	}

	return NULL;
}
