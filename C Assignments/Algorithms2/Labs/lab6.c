#include <stdio.h>

void printBuffer(char *b);

int main() {
	char buffer1[] = { 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '.' };
	char buffer2[] = { 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '.' };
	char buffer3[80];

	scanf("%s", &buffer3);

	printf("Buffer1: %s \nBuffer2: %s \nbuffer3: %s\n", buffer1, buffer2, buffer3);

	char *pBuffer = buffer3;

	printBuffer(pBuffer);
	printBuffer(pBuffer + 5);

	return 0;
}

void printBuffer(char *b) {
	int i = 0;
	while (*(b + i) != '\0') {
		printf("%c", *(b + i));
		i++;
	}
	printf("\n");
}