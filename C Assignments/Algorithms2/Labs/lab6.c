/*
 * Title:	lab6.c
 * Author:	Dilpreet Chana
 * Description:	Operations on char arrays
**/

#include <stdio.h>
#include <ctype.h>

void Reverse(char *string);
int getLength(char *string);
void parseSentence(char *string);

int main(void){
	
	char buffer[] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','.','\0'};
	char buffer2[] = "this is the second buffer.";
	char buffer3[80];

	//printf("%d\n", (int)('a'));

	scanf("%[^\n]s", buffer3);
	printf("-==== 3 BUFFERS ====-\n");
	printf("%s\n%s\n%s\n", buffer, buffer2, buffer3);

	char *pBuffer = buffer3;
	printf("-==== FIRST CHAR OF BUFFER3 ===-\n");
	printf("%c\n", *pBuffer);

	printf("-==== FULL BUFFER3 ====-\n");
	for (int i = 0; ; i++){
		if(*pBuffer == '\0'){break;}
	 	printf("%c", *pBuffer);
	 	pBuffer++;
	}

	printf("\n%s\n", buffer3);
	Reverse(buffer3);
	printf("\n%s\n", buffer3);
	parseSentence("Hello World, how are you");


	return 0;
}

void Reverse(char *string){
	char tmp;
	int len = getLength(string);
	int val;
	val = (len%2 == 0) ? len/2 : (len/2)+1;
	for (int i = 0; i < val; i++){
		tmp = *(string+len-1-i);
		*(string+len-1-i) = *(string+i);
		*(string+i) = tmp;
	}
}

int getLength(char *string){
	int count = 0;
	while (*(string+count) != '\0'){
		count ++;
	}
	return count;
}


void parseSentence(char *string){

	char *myString = string;
	int flag = 0;

	printf("\n");
	while (*myString != '\0'){
		if ( isalpha(*myString) ){
			printf("%c", *myString);
			flag = 0;
		}
		else if (flag == 0){
			printf("\n");
			flag = 1;
		}
		myString++;
	}
	printf("\n");

}
